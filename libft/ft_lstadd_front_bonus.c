/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:54:23 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:04:42 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
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
	while (tmp)
	{
		printf("%s -> ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (0);
}*/