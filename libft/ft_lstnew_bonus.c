/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:47:13 by czuniga-          #+#    #+#             */
/*   Updated: 2025/02/05 20:06:50 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int	main(void)
{
	int	num = 42;
	t_list *head = ft_lstnew(&num);
	if (head != NULL)
	{
		printf("nuevo nodo con valor: %d\n", *(int *)(head->content));
	}
	else
		printf("Error al crear nuevo nodo\n");
	free(head);
	return (0);
}*/