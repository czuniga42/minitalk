/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:57:31 by czuniga-          #+#    #+#             */
/*   Updated: 2025/07/01 23:22:42 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <signal.h>
#include <unistd.h>

typedef struct s_server_data
{
	sig_atomic_t	bit;
	sig_atomic_t	flag;
	sig_atomic_t	client_pid;
}	t_server_data;

volatile t_server_data	g_server = {0, 0, 0};

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	g_server.bit = (sig == SIGUSR2);
	g_server.flag = 1;
	g_server.client_pid = info->si_pid;
	kill(g_server.client_pid, SIGUSR1); // ✅ confirmación al cliente
}

void	print_pid(void)
{
	char	buffer[20];
	int		pid;
	int		len;
	char	c;

	pid = getpid();
	len = 0;
	write(1, "Server PID: ", 12);
	if (pid == 0)
		write(1, "0", 1);
	while (pid > 0)
	{
		buffer[len++] = (pid % 10) + '0';
		pid /= 10;
	}
	while (--len >= 0)
	{
		c = buffer[len];
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

void	handle_char(void)
{
	static int				bit_index = 0;
	static unsigned char	c = 0;

	c |= (g_server.bit << (7 - bit_index));
	bit_index++;
	if (bit_index == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		bit_index = 0;
	}
	g_server.flag = 0;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	print_pid();
	while (1)
	{
		pause();
		if (g_server.flag)
			handle_char();
	}
}
 */

 #include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_server
{
	volatile sig_atomic_t bit;           // Bit recibido en la señal (0 o 1)
	volatile sig_atomic_t flag;          // Flag para sincronización con el cliente
	int                    bits_received;  // Número de bits recibidos para la pieza actual
	int                    state;          // Estado actual: 0=tamaño,1=inicio,2=mensaje,3=fin
	int                    msg_len;        // Tamaño del mensaje esperado
	int                    chars_received; // Número de caracteres recibidos
	char                   *msg;           // Buffer dinámico para el mensaje
	pid_t                  client_pid;     // PID del cliente que envía (para confirmar)
} t_server;

t_server g_server = {0};

// Función para imprimir un número entero
void ft_putnbr_fd(int n, int fd)
{
	char c;

	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

// Resetea el estado para un nuevo mensaje
void reset_server(void)
{
	free(g_server.msg);
	g_server.msg = NULL;
	g_server.bits_received = 0;
	g_server.state = 0;
	g_server.msg_len = 0;
	g_server.chars_received = 0;
	g_server.client_pid = 0;
}

// Función que procesa el bit recibido y arma el mensaje
void handle_bit(void)
{
	static int bit_count = 0;
	static unsigned int current = 0;

	current = (current << 1) | g_server.bit;
	bit_count++;

	if (g_server.state == 0)
	{
		// Recibiendo tamaño (32 bits)
		if (bit_count == 32)
		{
			g_server.msg_len = current;
			if (g_server.msg_len <= 0)
				reset_server();
			else
			{
				g_server.msg = malloc(g_server.msg_len + 1);
				if (!g_server.msg)
					exit(1);
				g_server.state = 1;
			}
			bit_count = 0;
			current = 0;
		}
	}
	else if (g_server.state == 1)
	{
		// Esperando 8 bits ceros para inicio
		if (bit_count == 8)
		{
			if (current == 0)
				g_server.state = 2;
			else
				reset_server();
			bit_count = 0;
			current = 0;
		}
	}
	else if (g_server.state == 2)
	{
		// Recibiendo mensaje (8 bits por caracter)
		if (bit_count == 8)
		{
			g_server.msg[g_server.chars_received++] = (char)current;
			bit_count = 0;
			current = 0;
			if (g_server.chars_received == g_server.msg_len)
				g_server.state = 3;
		}
	}
	else if (g_server.state == 3)
	{
		// Esperando 8 bits ceros para fin
		if (bit_count == 8)
		{
			if (current == 0)
			{
				g_server.msg[g_server.chars_received] = '\0';
				write(1, g_server.msg, g_server.msg_len);
				write(1, "\n", 1);
			}
			reset_server();
			bit_count = 0;
			current = 0;
		}
	}

	g_server.flag = 0;
}

// Handler para señales SIGUSR1 y SIGUSR2
void sigusr_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (g_server.client_pid != info->si_pid)
	{
		// Si cambia el cliente, reiniciamos para recibir mensaje nuevo
		reset_server();
		g_server.client_pid = info->si_pid;
	}
	if (signum == SIGUSR1)
		g_server.bit = 0;
	else if (signum == SIGUSR2)
		g_server.bit = 1;
	else
		return;
	handle_bit();
	// Confirmamos recepción al cliente para que envie siguiente bit
	kill(g_server.client_pid, SIGUSR1);
}

int main(void)
{
	struct sigaction sa;

	g_server.state = 0;

	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);

	sa.sa_sigaction = sigusr_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();

	return (0);
}
