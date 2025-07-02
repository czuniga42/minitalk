/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:50:30 by czuniga-          #+#    #+#             */
/*   Updated: 2025/07/02 23:10:41 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_server
{
	volatile sig_atomic_t bit;
	volatile sig_atomic_t flag;
	int                    bits_received;
	int                    state;
	int                    msg_len;
	int                    chars_received;
	char                   *msg;
	pid_t                  client_pid;
}	t_server;

extern t_server g_server;

void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	handle_state(void);
void	reset_server(void);
void	sigusr_handler(int signum, siginfo_t *info, void *context);

#endif