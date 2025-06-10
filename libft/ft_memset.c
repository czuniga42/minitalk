/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:31:13 by czuniga-          #+#    #+#             */
/*   Updated: 2024/12/14 19:13:42 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n--)
	{
		*str = (unsigned char) c;
		str++;
	}
	return (s);
}
/* 
int	main(void)
{
	char	str[10] = "BBBBBBBBB";

	printf("s es: %s\n", str);
	ft_memset(str, '4', 5);
	printf("after memset: %s\n", str);
	return (0);
} */