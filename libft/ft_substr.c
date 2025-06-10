/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:52:59 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:12:42 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	substr_len;

	if (!s)
	{
		return (NULL);
	}
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	substr_len = s_len - start;
	if (substr_len > len)
		substr_len = len;
	substr = (char *)malloc(substr_len + 1);
	if (!substr)
		return (NULL);
	ft_memcpy(substr, (s + start), substr_len);
	substr[substr_len] = '\0';
	return (substr);
}
/*
int	main(void)
{
	char const	*str1 = "Hola, tengo cuatro camellos";
	char		*sub1 = ft_substr(str1, 6, 10);

	printf("subcadena 1: %s\n", sub1);
	free(sub1);
	return (0);
}*/
