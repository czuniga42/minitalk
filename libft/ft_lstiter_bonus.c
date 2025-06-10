/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:45:27 by czuniga-          #+#    #+#             */
/*   Updated: 2025/01/28 18:07:19 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
int	main(void)
{
	t_list	*first = malloc(sizeof(t_list));
	t_list	*second = malloc(sizeof(t_list));
	t_list	*third = malloc(sizeof(t_list));

	first->content = ft_strdup ("Node 1");
	first->next = second;

	second->content = ft_strdup ("Node 2");
	second->next = third;

	third->content = ft_strdup ("Node 3");
	third->next = NULL;

	void ft_putstr_fdd(void *content)
	{
		char *str = (char *)content;
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
		write(1, "\n", 1);
	}
	ft_lstiter(first, ft_putstr_fdd);
	free(first);
	free(second);
	free(third);
	return (0);
}*/