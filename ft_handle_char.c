/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:08:16 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/12 20:07:05 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_char(char c, t_params params, t_dca *str)
{
	if (params.flags & MINUS)
		if (ft_dca_add(str, c) == -1)
			return (-1);
	while (params.width > 1)
	{
		if (params.flags & ZERO)
		{
			if (ft_dca_add(str, '0') == -1)
				return (-1);
		}
		else
		{
			if (ft_dca_add(str, ' ') == -1)
				return (-1);
		}
		params.width--;
	}
	if (!(params.flags & MINUS))
		if (ft_dca_add(str, c) == -1)
			return (-1);
	return (0);
}
