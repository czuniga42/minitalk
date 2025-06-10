/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:01:18 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:07:04 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*lst = NULL;

	t_list	*node1 = ft_lstnew("1");
	t_list	*node2 = ft_lstnew("2");
	t_list	*node3 = ft_lstnew("3");

	ft_lstadd_front(&lst, node1);
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node3);

	t_list *tmp = lst;
	while (tmp)
	{
		printf("%s -> ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");
	printf("En la lista hay %d nodos \n", ft_lstsize(lst));
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (0);
}*/