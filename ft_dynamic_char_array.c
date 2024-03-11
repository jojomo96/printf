/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynamic_char_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:12:22 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/11 16:12:02 by jmoritz          ###   ########.fr       */
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

int	ft_dca_add_str(t_dca *array, const char *str, size_t len)
{
	size_t	new_capacity;
	char	*new_data;

	if (array->size + len >= array->capacity)
	{
		new_capacity = array->capacity * 2;
		if (new_capacity < array->size + len)
			new_capacity = array->size + len;
		new_data = (char *)malloc(new_capacity * sizeof(char));
		if (!new_data)
			return (-1);
		ft_memcpy(new_data, array->data, array->size * sizeof(char));
		free(array->data);
		array->data = new_data;
		array->capacity = new_capacity;
	}
	ft_memcpy(array->data + array->size, str, len);
	array->size += len;
	return (0);
}

int	ft_dca_add(t_dca *array, char element)
{
	size_t	new_capacity;
	char	*new_data;

	if (array->size == array->capacity)
	{
		if (array->capacity > 0)
		{
			new_capacity = array->capacity * 2;
		}
		else
		{
			new_capacity = 1;
		}
		new_data = (char *)malloc(new_capacity * sizeof(char));
		if (!new_data)
		{
			return (-1);
		}
		ft_memcpy(new_data, array->data, array->size * sizeof(char));
		free(array->data);
		array->data = new_data;
		array->capacity = new_capacity;
	}
	array->data[array->size++] = element;
	return (0);
}

int	ft_dca_print(t_dca *array)
{
	int	error;

	error = write(1, array->data, array->size);
	if (error == -1)
		return (-1);
	return (array->size);
}

void	ft_dca_free(t_dca *array)
{
	free(array->data);
	array->data = NULL;
	array->size = 0;
	array->capacity = 0;
}
