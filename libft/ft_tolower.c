/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:58:52 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:13:02 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/*
int	main(void)
{
	char	c = 'M';

	printf("Carácter: %c\n", c);
	printf("Resultado: %c\n", ft_tolower(c));
	return (0);
}*/