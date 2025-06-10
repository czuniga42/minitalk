/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:31:34 by czuniga-          #+#    #+#             */
/*   Updated: 2025/04/08 15:51:57 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (str[len])
		len += write(1, &str[len], 1);
	return (len);
}
