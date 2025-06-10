/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:45:25 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:00:49 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	c1 = 'a';
	char	c2 = 'D';
	char	c3 = '5';
	char	c4 = '\t';

	printf("%c: %d\n", c1, ft_isascii(c1));
	printf("%c: %d\n", c2, ft_isascii(c2));
	printf("%c: %d\n", c3, ft_isascii(c3));
	printf("%c: %d\n", c4, ft_isascii(c4));
	return (0);
}*/