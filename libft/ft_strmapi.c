/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:10:22 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 10:49:20 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = (char *)malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char const	*str = "Hola mundo";
	char	*result;
	char	ft_replacestr(unsigned int i, char c)
	{
		(void) i;
		(void) c;
		return ('*');
	}
	result = ft_strmapi(str, ft_replacestr);
	printf("str: %s\n", str);
	printf("result: %s\n", result);
	free(result);
	return (0);
}*/