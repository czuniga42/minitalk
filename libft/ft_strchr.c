/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:53:31 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:10:47 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
		{
			return ((char *) s);
		}
		s++;
	}
	if ((char) c == '\0')
	{
		return ((char *) s);
	}
	return (NULL);
}

/*
int main(void)
{
	const char	*str = "Hola, mundo";
	char	c = 'm';
	char	*result = ft_strchr(str, c);

	printf("%c en: %s\n", c, result);
	return (0);
}*/