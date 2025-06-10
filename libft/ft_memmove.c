/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:08:25 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:08:02 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (d > s)
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	else
	{
		while (n--)
		{
			*(d++) = *(s++);
		}
	}
	return (dest);
}
/*
int	main(void)
{
    unsigned char	src[] = "abcdefghijk";
    unsigned char	dest[50];

    ft_memmove(src, src + 2, 5);
    printf("%s\n", src);
    return(0);
}*/