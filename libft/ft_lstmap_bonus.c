/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:08:33 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:06:41 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*content;

	new_lst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/*
int	main(void)
{
	void	*duplicate(void *content)
	{
    	int *value = (int *)content;
    	*value *= 2;
    	return (value);
	}
	 
	t_list	*lst = NULL;
	int	*first = malloc(sizeof(int));
	int	*second = malloc(sizeof(int));
	int	*third = malloc(sizeof(int));

	*first = 1;
    *second = 2;
    *third = 3;

    ft_lstadd_back(&lst, ft_lstnew(first));
    ft_lstadd_back(&lst, ft_lstnew(second));
    ft_lstadd_back(&lst, ft_lstnew(third));
	
	t_list	*tmp = lst;
	printf("Lista original: ");
    while (tmp)
	{
		printf("%d -> ", *(int *)tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");
	
	t_list *new_lst = ft_lstmap(lst, duplicate, free);

	t_list	*temp2 = new_lst;
 	printf("Lista modificada: ");
    while (temp2)
	{
		printf("%d -> ", *(int *)temp2->content);
		temp2 = temp2->next;
	}
	printf("NULL\n");
    return 0;
}*/