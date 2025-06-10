/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:09:05 by czuniga-          #+#    #+#             */
/*   Updated: 2025/04/08 15:51:58 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_pointer(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	len += write (1, "0x", 2);
	len += ft_print_hex((unsigned long)ptr, 'x');
	return (len);
}
