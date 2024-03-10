/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:32:43 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/10 18:40:03 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_string(char *s, t_params params, t_dca *str)
{
	int	len;

	if (s == NULL)
		s = "(null)";
	len = ft_get_min_len(params);
	if (params.flags & MINUS)
		ft_dca_add_str(str, s);
	while (len > ft_strlen(s))
	{
		if (params.flags & ZERO)
			ft_dca_add(str, '0');
		else
			ft_dca_add(str, ' ');
		len--;
	}
	if (!(params.flags & MINUS))
		ft_dca_add_str(str, s);
}
