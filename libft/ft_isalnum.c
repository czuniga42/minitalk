/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:08:19 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:10:08 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	c1 = 'a';
	char	c2 = 'B';
	char	c3 = '3';
	char	c4 = '\0';

	printf("%c: %d\n", c1, ft_isalnum(c1));
	printf("%c: %d\n", c2, ft_isalnum(c2));
	printf("%c: %d\n", c3, ft_isalnum(c3));
	printf("%c: %d\n", c4, ft_isalnum(c4));
	return (0);
}*/