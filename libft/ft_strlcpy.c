/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:50:53 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:11:19 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char		dst[10];
	const char	src[] = "Hola, mundo!";
	
	size_t	len = ft_strlcpy(dst, src, sizeof(dst));

	printf("destino: %s\n", dst);
	printf("longitud de src: %zu\n", len);
	return (0);
}*/