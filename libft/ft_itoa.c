/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:41:38 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:03:46 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	long	num;

	num = n;
	len = ft_num_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (len-- && str[len] != '-')
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
/*
int	main(void)
{
	int		n = -300;
	char	*result = ft_itoa(n);

	printf("ft_itoa(%d): %s\n", n, result);
	free(result);
	return (0);
}*/