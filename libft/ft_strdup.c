/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:35:25 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:10:53 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*dup;
	size_t		len;

	len = ft_strlen(s);
	dup = malloc (len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len + 1);
	return (dup);
}
/*
int	main(void)
{
	char	*str = "Hola, mundo!";
	char	*dup;

	dup = ft_strdup(str);
	if (!dup)
	{
		printf("Error\n");
		return (1);
	}
	printf("Cadena original: %s\n", str);
	printf("Cadena duplicada: %s\n", dup);
	free(dup);
	return (0);
}*/