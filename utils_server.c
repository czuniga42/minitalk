/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:34:17 by czuniga-          #+#    #+#             */
/*   Updated: 2025/07/02 23:39:23 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"

static void handle_state_0(unsigned int *current, int *bit_count)
{
	if (*bit_count == 32)
	{
		g_server.msg_len = *current;
		if (g_server.msg_len <= 0)
			reset_server();
		else
		{
			g_server.msg = ft_calloc(g_server.msg_len + 1, 1);
			if (!g_server.msg)
				exit(1);
			g_server.state = 1;
		}
		*bit_count = 0;
		*current = 0;
	}
}

static void handle_state_1(unsigned int *current, int *bit_count)
{
	if (*bit_count == 8)
	{
		if (*current == 0)
			g_server.state = 2;
		else
			reset_server();
		*bit_count = 0;
		*current = 0;
	}
}

static void handle_state_2(unsigned int *current, int *bit_count)
{
	if (*bit_count == 8)
	{
		g_server.msg[g_server.chars_received++] = (char)*current;
		*bit_count = 0;
		*current = 0;
		if (g_server.chars_received == g_server.msg_len)
			g_server.state = 3;
	}
}

static void handle_state_3(unsigned int *current, int *bit_count)
{
	if (*bit_count == 8)
	{
		if (*current == 0)
		{
			ft_putstr_fd(g_server.msg, 1);
			write(1, "\n", 1);
		}
		*bit_count = 0;
		*current = 0;

		// 🧠 Añade este ACK antes de reiniciar
		kill(g_server.client_pid, SIGUSR1);

		reset_server();
	}
}

void handle_state(void)
{
	static int bit_count = 0;
	static unsigned int current = 0;

	current = (current << 1) | g_server.bit;
	bit_count++;

	if (g_server.state == 0)
		handle_state_0(&current, &bit_count);
	else if (g_server.state == 1)
		handle_state_1(&current, &bit_count);
	else if (g_server.state == 2)
		handle_state_2(&current, &bit_count);
	else if (g_server.state == 3)
		handle_state_3(&current, &bit_count);
}
