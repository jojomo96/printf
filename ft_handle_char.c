/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:08:16 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/11 16:08:45 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_char(char c, t_params params, t_dca *str)
{
	if (params.flags & MINUS)
		ft_dca_add(str, c);
	while (params.width > 1)
	{
		if (params.flags & ZERO)
			ft_dca_add(str, '0');
		else
			ft_dca_add(str, ' ');
		params.width--;
	}
	if (!(params.flags & MINUS))
		ft_dca_add(str, c);
}
