/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:41:31 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:12:35 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_isinset(s1[start], set))
	{
		start++;
	}
	while (end > start && ft_isinset(s1[end - 1], set))
	{
		end--;
	}
	return (ft_substr(s1, start, end - start));
}
/*
int	main(void)
{
	char const	*s1 = "---Canela!!!";
	char const	*set = "-!";
	char		*result = ft_strtrim(s1, set);

	printf("Cadena recortada: %s\n", result);
	free(result);
	return (0);
}*/