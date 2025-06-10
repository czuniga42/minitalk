/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:13:01 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:10:59 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int	main(void)
{
	char	s[] = "Hola mundo";

	printf("cadena original: %s\n", s);
	void	ft_replacestr(unsigned int i, char *c)
	{
		(void) i;
		(void) c;

		*c = '*';
	}
	ft_striteri(s, ft_replacestr);
	printf("cadena: %s\n", s);
	return (0);
}*/