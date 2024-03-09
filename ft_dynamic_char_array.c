/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynamic_char_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:12:22 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/09 17:21:10 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dca_init(t_dca *array, size_t initial_capacity)
{
	array->data = (char *)ft_calloc(initial_capacity, sizeof(char));
	if (!array->data)
	{
		return (-1);
	}
	array->size = 0;
	array->capacity = initial_capacity;
	return (0);
}

int	dca_add(t_dca *array, char element)
{
	size_t	new_capacity;
	char	*new_data;

	if (array->size == array->capacity)
	{
		new_capacity = array->capacity * 2;
		new_data = ft_recalloc(array->data, array->capacity * sizeof(char),
				new_capacity * sizeof(char));
		if (!new_data)
		{
			return (-1);
		}
		array->data = new_data;
		array->capacity = new_capacity;
	}
	array->data[array->size++] = element;
	return (0);
}

void	dca_free(t_dca *array)
{
	free(array->data);
	array->data = NULL;
	array->size = 0;
	array->capacity = 0;
}
