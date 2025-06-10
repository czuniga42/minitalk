/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:52:17 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:11:11 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (size + srclen);
	i = 0;
	while (i < size - dstlen - 1 && src[i] != '\0')
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
/*
int	main(void)
{
	char	dst[20] = "Hola, ";
	const char	*src = "mundo!";
	size_t	size;
	size_t	result = ft_strlcat(dst, src, sizeof(dst));

	printf("Resultado %s\n", dst);
	printf("longitud: %zu\n", result);
	return (0);
}*/