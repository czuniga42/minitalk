/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:33:18 by czuniga-          #+#    #+#             */
/*   Updated: 2025/04/08 15:51:54 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	result;

	len = 0;
	if (n > 9)
		len = len + ft_print_unsigned(n / 10);
	result = (n % 10) + '0';
	len = len + write(1, &result, 1);
	return (len);
}
