/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:32:43 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/10 20:46:57 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_string(char *s, t_params params, t_dca *str)
{
	int	len;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (params.flags & PRECISION && params.precision < len)
		len = len - (len - params.precision);
	if (params.flags & MINUS)
		ft_dca_add_str(str, s, len);
	while (params.width > len)
	{
		if (params.flags & ZERO && !(params.flags & MINUS))
			ft_dca_add(str, '0');
		else
			ft_dca_add(str, ' ');
		params.width--;
	}
	if (!(params.flags & MINUS))
		ft_dca_add_str(str, s, len);
}
