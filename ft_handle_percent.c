/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:48:36 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/11 15:56:33 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_width(t_params params, t_dca *str)
{
	int	len;

	len = 1;
	if (params.width <= len)
		return ;
	while (params.width-- > len)
	{
		if (params.flags & ZERO && !(params.flags & MINUS))
			ft_dca_add(str, '0');
		else
			ft_dca_add(str, ' ');
	}
}

void	ft_handle_percent(t_params params, t_dca *str)
{
	if (params.flags & MINUS)
	{
		ft_dca_add(str, '%');
		ft_handle_width(params, str);
	}
	else
	{
		ft_handle_width(params, str);
		ft_dca_add(str, '%');
	}
}
