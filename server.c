/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:57:31 by czuniga-          #+#    #+#             */
/*   Updated: 2025/06/11 18:30:15 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void	ft_signal_handler(int signal, siginfo_t *info, void *context)
{
	static int		count_bit = 0;
	static unsigned char	c = 0;

	(void)context;
	if (signal == SIGUSR1)
		c |= (1 << count_bit);
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
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

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