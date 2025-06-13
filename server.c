/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:57:31 by czuniga-          #+#    #+#             */
/*   Updated: 2025/06/13 13:53:38 by czuniga-         ###   ########.fr       */
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
	}	t_data;

t_data	*g_data;

void	ft_free_and_print(void)
{
	ft_putstr_fd(g_data->message, 1);
	free(g_data->message);
	g_data->message = NULL;
	g_data->message_len = 0;
	g_data->client_pid = 0;
}

void	ft_init_data(t_data *data)
{
	data->client_pid = 0;
	data->c = 0;
	data->count_bit = 0;
	data->message = NULL;
	data->message_len = 0;
}

void	ft_reserve_space(void)
{
	char *new_message;
	
	new_message = malloc(g_data->message_len + 2);
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
		g_data->client_pid = info->si_pid;
	if (info->si_pid != g_data->client_pid)
		return ;
	if (signal == SIGUSR1)
		g_data->c |= (1 << g_data->count_bit);
	g_data->count_bit++;
	if (g_data->count_bit == 8)
	{
		ft_reserve_space();
		ft_putchar_fd(g_data->c, 1); // de prueba
		if (g_data->c == '\0')
			ft_free_and_print();
		g_data->count_bit = 0;
		g_data->c = 0;kill(info->si_pid, SIGUSR1);
		kill(info->si_pid, SIGUSR1);
	}
}

int main(void)
{
	struct	sigaction sa;
	g_data = malloc(sizeof(t_data));
	if (!g_data)
		return (1);
	ft_init_data(g_data);
	sa.sa_sigaction = ft_signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("servidor PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
