/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:36:35 by czuniga-          #+#    #+#             */
/*   Updated: 2025/06/05 16:18:35 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

/*
int	main(void)
{
	unsigned char	ptr[5] = "Hello";
	size_t			n = 5;
	size_t			i;

	printf("la cadena original es: %s\n", ptr);
	ft_bzero(ptr, n);

	printf("la cadena actualizada es:");
	while (i < 5)
	{
		printf("%d", ptr[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/
