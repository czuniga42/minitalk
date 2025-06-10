/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:41:25 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:07:39 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}
/*
int main(void)
{
	const unsigned char	s[] = "Caramelo de lima";
	unsigned char		d[50];

	ft_memcpy((unsigned char *)d + 2, s, 10);
	printf("El destino es: %s\n", d + 2);
	return (0);
}*/
