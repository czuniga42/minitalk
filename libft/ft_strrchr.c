/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:54:34 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:12:23 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char) c)
		{
			last = (char *)s;
		}
		s++;
	}
	if ((char) c == '\0')
	{
		return ((char *) s);
	}
	return (last);
}
/*
int main(void)
{
	const char	*str = "Hola, Carlitos!";
	char	c = 'a';
	char	*result = ft_strrchr(str, c);
	
	printf("última aparición de '%c': en la posición: %ld\n", c, (result - str));
	return (0);
}*/