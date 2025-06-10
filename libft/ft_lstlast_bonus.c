/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:12:14 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:06:02 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list	*lst = NULL;

	t_list	*node1 = ft_lstnew("Nodo 1");
	t_list	*node2 = ft_lstnew("Nodo 2");
	t_list	*node3 = ft_lstnew("Nodo 3");

	ft_lstadd_front(&lst, node1);
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node3);

	t_list	*tmp = lst;
	printf("Lista original: \n");
	while (tmp)
	{
		printf("%s -> ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");
	t_list	*last = ft_lstlast(lst);
	if (last)
	{
		printf("Ultimo nodo es: %s\n", (char *)last->content);
	}
	free(lst);
	return (0);
}*/