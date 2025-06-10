/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:32:26 by czuniga-          #+#    #+#             */
/*   Updated: 2025/04/08 15:52:02 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr(int n)
{
	char	result;
	int		len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		len = len + ft_print_nbr(n / 10);
	result = (n % 10) + '0';
	len = len + write(1, &result, 1);
	return (len);
}
