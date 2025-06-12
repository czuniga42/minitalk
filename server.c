/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:57:31 by czuniga-          #+#    #+#             */
/*   Updated: 2025/06/12 18:21:34 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct	s_data
	{
		pid_t			client_pid;
		int				count_bit;
		unsigned char	c;
		char			*message;
		size_t			message_len;
	} t_data;

	t_data	*g_data = NULL;

void	ft_reserve_space(void)
{
	char *new_message
	
	new_message = malloc (g_data->message_len + 2);
	if (!new_message)
		exit (1);
	if (g_data->message)
	{
		ft_memcpy(new_message, g_data->message, g_data->message_len);
		free(g_data->message);
	}
	new_message[g_data->message_len++] = g_data->c;
	new_message[g_data->message_len] = '\0';
	g_data->message = new_message;
}
	
void	ft_signal_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if(g_data->client_pid == 0)
		g_data->client_pid = info->si->pid;
	if (info->si_pid != g_data->client_pid)
		return ;
	if (signal == SIGUSR1)
		g_data->c |= (1 << g_data->count_bit);
	g_data->count_bit++;
	if (g_data->count_bit == 8)
	
	
	write(1, "Bit recibido: ", 14);
	if (signal == SIGUSR1)
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);

	write(1, "Estado de c: ", 13);
	print_bits(c);
	count_bit++;
	if (count_bit == 8) //cuando ya tiene los 8 bits)
	{
		write(1, &c, 1);
		write(1, "\n", 1);
		count_bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	struct	sigaction	sa;
	g_data = malloc(sizeof(t_data));
	if (!g_data)
		return (1);
	init_data(g_data);
	sa.sa_sigaction = ft_signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_ft("servidor PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}


/* signal es para SIGUSR1 Y 2, sigaction, etc..
1 = 1 bit, 2 = 0 bits
unistd para write, pause, getpid, etc..
stdlib para free 
se usan funciones estaticas porque al salir no se destruye y conserva su valor en repetitivas llamadas
teniendo en cuenta que se llama por cada bit
c |= (1 << count_bit) es igual a: 
int mask = 1 << count_bit  -> crea una mascara (un numero en bits) con el bit activado
c = c | mask -> aplicar OR para encender el bit en 'c'. solo cambia el 'bit'.
*/