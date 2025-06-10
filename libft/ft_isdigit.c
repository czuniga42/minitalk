/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:48:35 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:01:42 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
int	main(void)
{
	char	c1 = '5';
	char	c2 = 'B';
	char	c3 = '\0';

	printf("%c: %d\n", c1, ft_isdigit(c1));
	printf("%c: %d\n", c2, ft_isdigit(c2));
	printf("%c: %d\n", c3, ft_isdigit(c3));
	return (0);
}*/