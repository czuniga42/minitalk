/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:55:03 by czuniga-          #+#    #+#             */
/*   Updated: 2025/07/02 23:34:10 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

volatile sig_atomic_t g_ack = 0;

void	ack_handler(int signum)
{
	(void)signum;
	g_ack = 1;
}

void	send_bit(pid_t pid, int bit)
{
	g_ack = 0;
	if (bit == 0)
	{
		kill(pid, SIGUSR1);
		write(1, "0", 1);
	}
	else
	{
		kill(pid, SIGUSR2);
		write(1, "1", 1);
	}
	while (!g_ack)
		pause();
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
	write(1, " ", 1);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;
	int		len;
	int		i;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client <PID> <message>\n", 2);
		return (1);
	}
	pid = (pid_t)atoi(argv[1]);
	msg = argv[2];
	len = ft_strlen(msg);
	signal(SIGUSR1, ack_handler);
	i = 31;
	while (i >= 0)
		send_bit(pid, (len >> i--) & 1);
	send_char(pid, 0);
	i = 0;
	while (i < len)
		send_char(pid, msg[i++]);
	send_char(pid, 0);
	while (!g_ack)
		pause();
	ft_putstr_fd("\nMensaje enviado correctamente.\n", 1);
	return (0);
}
