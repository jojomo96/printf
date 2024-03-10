/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:08:16 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/10 18:29:41 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_char(char c, t_params params, t_dca *str)
{
	int	len;

	len = ft_get_min_len(params);
	if (params.flags & MINUS)
		ft_dca_add(str, c);
	while (len > 1)
	{
		if (params.flags & ZERO)
			ft_dca_add(str, '0');
		else
			ft_dca_add(str, ' ');
		len--;
	}
	if (!(params.flags & MINUS))
		ft_dca_add(str, c);
}
