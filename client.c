/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:55:03 by czuniga-          #+#    #+#             */
/*   Updated: 2025/06/13 17:50:10 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* handle_ack: //para confirmar la señal, sin modificar variables porq se usa pause */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void	handle_ack(int signal)
{
	//(void)signal;
	if (signal == SIGUSR1)
	{
		write(1, "confirmacion recibida", 21);
	}
}

void	send_char(pid_t server_pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		bit++;
		usleep(1000);  // Pequeña pausa para que el servidor procese cada bit
	}
	pause();  // Espera la confirmación del servidor y nos bloquea al llegar la señal
}

int	main(int argc, char **argv)
{
	struct sigaction sa;
	pid_t	server_pid;
	char	*message;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Uso: ./client [PID_SERVIDOR] [MENSAJE]\n", 2);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	sa.sa_handler = handle_ack;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	while (message[i]) //enviamos cada caracter del mensaje
		send_char(server_pid, message[i++]);
	send_char(server_pid, '\0');  // Final del mensaje
	return (0);
}
