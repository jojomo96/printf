/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynamic_char_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:12:22 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/09 18:12:57 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dca_init(t_dca *array, size_t initial_capacity)
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

int	ft_dca_add(t_dca *array, char element)
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

int	ft_dca_print(t_dca *array)
{
	int error;

	error = write(1, array->data, array->size);
	if(error == -1)
		return (-1);
	return (array->size);
}

int ft_dca_print_and_free(t_dca *array)
{
	int	size;

	size = ft_dca_print(array);
	ft_dca_free(array);
	return (size);
}

void	ft_dca_free(t_dca *array)
{
	free(array->data);
	array->data = NULL;
	array->size = 0;
	array->capacity = 0;
}
