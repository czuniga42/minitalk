/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:41:09 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:05:27 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
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
	
	first->next = third;
	ft_lstdelone(second, free);
	
	printf("Lista despues de borrar el segundo nodo: \n");
	tmp = lst;
	while (tmp)
	{
		printf("%s -> ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");

	free(first);
	free(third);
	return (0);
}*/