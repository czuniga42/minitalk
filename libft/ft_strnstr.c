/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:43:10 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:12:19 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *) big);
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (j < len - i && little[j] && big[i + j] == little[j])
			{
				j++;
			}
			if (little[j] == '\0')
			{
				return ((char *)(big + i));
			}
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	const char		big[] = "Hello, it's me";
	const char		little[] = "it's";
	char			*result;

	result = ft_strnstr(big, little, 22);
	if (result)
	{
		printf("Subcadena encontrada: %s\n", result);
	}
	else
	{
		printf("subcadena no encontrada");
	}
	return (0);
}*/