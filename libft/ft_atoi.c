/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:16:41 by czuniga-          #+#    #+#             */
/*   Updated: 2025/06/06 19:44:54 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
	{
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
		{
			sign = -1;
		}
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}
/* 
int	main(void)
{
	const char	nptr1[] = "-01";
	const char	nptr2[] = "-1234";
	const char	nptr3[] = "+567";
	printf("%d\n", ft_atoi(nptr1));
	printf("%d\n", ft_atoi(nptr2));
	printf("%d\n", ft_atoi(nptr3));
	return(0);
} */
