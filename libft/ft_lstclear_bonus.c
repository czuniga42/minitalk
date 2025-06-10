/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:02:45 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:05:12 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
/*
int	main(void)
{
	t_list	*lst = NULL;

	t_list	*first = malloc(sizeof(t_list));
	t_list	*second = malloc(sizeof(t_list));
	t_list	*third = malloc(sizeof(t_list));

	first->content = ft_strdup ("Node 1");
	first->next = second;

	second->content = ft_strdup ("Node 2");
	second->next = third;

	third->content = ft_strdup ("Node 3");
	third->next = NULL;

	lst = first;

	t_list	*tmp = lst;
	printf("Lista original: \n");
	while (tmp)
	{
		printf("%s -> ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");

	ft_lstclear(&lst, free);
	printf("Lista despues de borrar todos los nodos: \n");
	if (!lst)
		printf("NULL\n");
	else
	{
		tmp = lst;
		while (tmp)
		{
			printf("%s -> ", (char *)tmp->content);
			tmp = tmp->next;
		}
		printf("NULL\n");
	}
	return (0);
}*/