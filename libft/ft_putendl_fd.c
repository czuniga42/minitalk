/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:12:34 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:08:32 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(fd, s++, 1);
	}
	write(fd, "\n", 1);
}
/*
int	main(void)
{
	char	s1[] = "manzana verde";
	char	s2[] = "manzana roja"; 

	ft_putendl_fd(s1, 1);
	ft_putendl_fd(s2, 1);
	return (0);
}*/