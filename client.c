/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:55:03 by czuniga-          #+#    #+#             */
/*   Updated: 2025/07/05 15:34:48 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

volatile sig_atomic_t	g_ack = 0;

void	ft_ack_handler(int signum)
{
	(void)signum;
	g_ack = 1;
}

void	ft_send_bit(pid_t pid, int bit)
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

void	ft_send_char(pid_t pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		ft_send_bit(pid, (c >> i) & 1);
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
		return (ft_putstr_fd("Usage: ./client <PID> <message>\n", 2), 1);
	pid = (pid_t)(ft_atoi(argv[1])); //convierte el pid que esta como argumento a entero
	msg = argv[2]; //guarda el mensaje
	len = ft_strlen(msg); //guarda la longitud de mensaje
	signal(SIGUSR1, ft_ack_handler);//toma dos argumentos: el entero que representa la señal(SIGUSR1 o SIGUSR2), y un puntero a una funcion.-signal: forma sencilla de manejar señalesdel sistema operativo como i
	i = 31;
	while (i >= 0)
		ft_send_bit(pid, (len >> i--) & 1); //1ro esperara por 32 bits que es el tamaño completo del mensaje
	write(1, " ", 1);
	ft_send_char(pid, 0); //envia 8bits (0)para indica que ya envio el tamaño y toca el  mensaje. seusa como separador
	i = 0;
	while (i < len)
		ft_send_char(pid, msg[i++]); //aqui envia el mensaje
	ft_send_char(pid, 0); //aqui vuelve a separar con ceros
	usleep(800); //espera 800 microsegundos por si hay retrasos
	ft_putstr_fd("\nMensaje enviado correctamente.\n", 1);
	return (0);
}
