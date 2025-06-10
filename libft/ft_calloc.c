/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:19:37 by czuniga-          #+#    #+#             */
/*   Updated: 2025/04/10 18:53:55 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
/* 
int	main(void)
{
	int	*array;
	size_t	n = 5;
	size_t	i = 0;

	array = ft_calloc(5, sizeof(int));
	if (!array)
	{
		printf("Error al asignar memoria\n");
		return (1);
	}
	while (i < n)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
	free(array);
	return (0);
} */
