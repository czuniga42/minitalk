/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:33:33 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:04:51 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}
/*
int	main(void)
{
	t_list	*lst = NULL;

	t_list	*node1 = ft_lstnew("Nodo 1");
	t_list	*node2 = ft_lstnew("Nodo 2");
	t_list	*node3 = ft_lstnew("Nodo 3");

	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	ft_lstadd_back(&lst, node3);

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