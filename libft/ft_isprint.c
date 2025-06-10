/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:00:01 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:02:05 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	c1 = 'a';
	char	c2 = '3';
	char	c3 = '\a';
	char	c4 = '\0';

	printf("%c: %d\n", c1, ft_isprint(c1));
	printf("%c: %d\n", c2, ft_isprint(c2));
	printf("%c: %d\n", c3, ft_isprint(c3));
	printf("%c: %d\n", c4, ft_isprint(c4));
	return (0);
}*/