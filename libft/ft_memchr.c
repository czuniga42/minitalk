/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:17:02 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 14:11:51 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	value;

	str = (unsigned char *) s;
	value = (unsigned char) c;
	while (n--)
	{
		if (*str == value)
			return ((void *) str);
		str++;
	}
	return (NULL);
}
/*
int main(void)
{
	unsigned char	str[] = "Hola mundo";
	unsigned char	c = 'm';

	unsigned char	*result = ft_memchr(str, c, sizeof(str));
	if (result)
	{
		printf("%c encontrado en la posición %ld\n", c, (result - str));
	}
	else
	{
		printf("%c no encontrado\n", c);
	}
	return (0);
}*/