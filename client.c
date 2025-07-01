/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:55:03 by czuniga-          #+#    #+#             */
/*   Updated: 2025/07/01 23:22:08 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <signal.h>
#include <unistd.h>
#include <stdlib.h>

volatile sig_atomic_t	g_ack = 0; // ✅ única global del cliente

void	ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

void	send_bit(pid_t pid, int bit)
{
	g_ack = 0;
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	while (!g_ack)
		pause(); // 🕓 espera confirmación del server
}

void	send_char(pid_t pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_bit(pid, (c >> i) & 1);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;
	int		i;

	if (argc != 3)
		return (1);
	pid = (pid_t)atoi(argv[1]);
	msg = argv[2];
	signal(SIGUSR1, ack_handler);
	i = 0;
	while (msg[i])
	{
		send_char(pid, msg[i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
 */

 #include <signal.h>
#include <unistd.h>
#include <stdlib.h>

volatile sig_atomic_t g_ack = 0;

// Handler que confirma la recepción de la señal en el servidor
void ack_handler(int signum)
{
	(void)signum;
	g_ack = 1;
}

// Enviar un bit y esperar confirmación
void send_bit(pid_t pid, int bit)
{
	g_ack = 0;
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	while (!g_ack)
		pause();
}

// Enviar un carácter (8 bits)
void send_char(pid_t pid, unsigned char c)
{
	int i = 7;
	while (i >= 0)
	{
		send_bit(pid, (c >> i) & 1);
		i--;
	}
}

// Enviar entero de 32 bits (tamaño)
void send_int(pid_t pid, unsigned int n)
{
	int i = 31;
	while (i >= 0)
	{
		send_bit(pid, (n >> i) & 1);
		i--;
	}
}

int main(int argc, char **argv)
{
	pid_t pid;
	char *msg;
	int len;
	int i;

	if (argc != 3)
		return (1);
	pid = (pid_t)atoi(argv[1]);
	msg = argv[2];
	len = 0;
	while (msg[len])
		len++;

	signal(SIGUSR1, ack_handler);

	// Enviar tamaño
	send_int(pid, len);

	// Enviar 8 bits ceros para inicio
	send_char(pid, 0);

	// Enviar mensaje
	for (i = 0; i < len; i++)
		send_char(pid, msg[i]);

	// Enviar 8 bits ceros para fin
	send_char(pid, 0);

	return (0);
}
