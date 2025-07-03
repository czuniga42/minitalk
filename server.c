/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:57:31 by czuniga-          #+#    #+#             */
/*   Updated: 2025/07/03 14:22:14 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_server g_server = {0};

void ft_reset_server(void)
{
	free(g_server.msg);
	g_server.msg = NULL;
	g_server.bits_received = 0;
	g_server.state = 0;
	g_server.msg_len = 0;
	g_server.chars_received = 0;
}

void	ft_sigusr_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (g_server.client_pid != info->si_pid)
	{
		ft_reset_server();
		g_server.client_pid = info->si_pid;
	}
	if (signum == SIGUSR1)
		g_server.bit = 0;
	else if (signum == SIGUSR2)
		g_server.bit = 1;
	ft_handle_state();
	usleep(30);
	kill(g_server.client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	g_server.state = 0;
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sa.sa_sigaction = ft_sigusr_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
