/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:04:47 by czuniga-          #+#    #+#             */
/*   Updated: 2025/04/08 15:52:00 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	va_list	args_copy;
	int		count;

	count = 0;
	va_start(args, format);
	va_copy(args_copy, args);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += ft_handle_conversion(*format, args_copy);
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(args_copy);
	va_end(args);
	return (count);
}
/* 
int	main(void)
{
	int				c = 'A';
	char			*str = "Hola";
	int				num = 42;
	void			*ptr = &num;
	int				int_ten = -256;
	unsigned int	num2 = 142;

	ft_printf("\nCON FT_PRINTF\n");
	ft_printf("%c\n", c);
	ft_printf("%s\n", str);
	ft_printf("%p\n", ptr);
	ft_printf("%d\n", num);
	ft_printf("%i\n", int_ten);
	ft_printf("%u\n", num2);
	ft_printf("%x\n", num);
	ft_printf("%X\n", num);
	ft_printf("%%\n");
	ft_printf("%s : %d\n", str, num);
	ft_printf("\n");
	printf("CON PRINTF\n");
	printf("%c\n", c);
	printf("%s\n", str);
	printf("%p\n", ptr);
	printf("%d\n", num);
	printf("%i\n", int_ten);
	printf("%u\n", num2);
	printf("%x\n", num);
	printf("%X\n", num);
	printf("%%\n");
	printf("%s : %d\n", str, num);
	return (0);
} */