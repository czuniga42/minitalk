/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:23:28 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:13:14 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
int main(void)
{
	char	c = 'a';
	
	printf("Carácter: %c\n", c);
	printf("Resultado: %c\n", ft_toupper(c));
	return (0);
}*/