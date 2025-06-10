/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:39:58 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:08:59 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_total_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free(array);
}

static char	**ft_count_words(const char *str, char delim)
{
	size_t	count;
	char	**result;

	count = 0;
	while (*str)
	{
		while (*str == delim)
			str++;
		if (*str)
		{
			count++;
			while (*str != delim && *str)
				str++;
		}
	}
	result = malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (result);
}

static int	ft_fill_words(char **result, char const *s, char c)
{
	int			i;
	const char	*start;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[i] = ft_substr(start, 0, s - start);
			if (!result[i])
			{
				ft_total_free(result);
				return (0);
			}
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = ft_count_words(s, c);
	if (!result)
		return (NULL);
	if (!ft_fill_words(result, s, c))
		return (NULL);
	return (result);
}
/*
int	main(void)
{
	char	**result;
	int i;

	result = ft_split("llevo unas converse negras", ' ');
	if (result)
	{
		i = 0;
		while (result[i])
		{
			printf("substring %d: %s\n", i + 1, result[i]);
			i++;
		}
	}
	ft_total_free(result);
	return (0);
}*/
