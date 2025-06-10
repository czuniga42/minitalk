/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:54:25 by czuniga-          #+#    #+#             */
/*   Updated: 2025/04/08 15:50:37 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handle_conversion(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}
