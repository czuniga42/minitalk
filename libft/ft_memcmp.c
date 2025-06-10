/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:27:09 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:07:24 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *) s1;
	str2 = (const unsigned char *) s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
/*
int main(void)
{
	const unsigned char	str1[] = "Hola";
	const unsigned char	str2[] = "Holi";
	int	result;

	result = ft_memcmp(str1, str2, 4);
	if (result == 0)
		printf("Los bloques son iguales\n");
	else if (result < 0)
		printf("s1 es menor que s2\n");
	else
		printf("s1 es mayor que s2\n");
	return (0);
}*/
