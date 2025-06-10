/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:30:01 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:00:26 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	c1 = 'a';
	char	c2 = 'B';
	char	c3 = '1';
	char	c4 = '\0';

	printf("%c: %d\n", c1, ft_isalpha(c1));
	printf("%c: %d\n", c2, ft_isalpha(c2));
	printf("%c: %d\n", c3, ft_isalpha(c3));
	printf("%c: %d\n", c4, ft_isalpha(c4));
	return (0);
}*/