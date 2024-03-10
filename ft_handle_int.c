/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:48:11 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/10 22:34:24 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_persition(t_params *params, long *n, t_dca *str)
{
	if (*n >= 0 && (params->flags & (PLUS | SPACE)))
	{
		if (params->flags & PLUS)
			ft_dca_add(str, '+');
		else
			ft_dca_add(str, ' ');
		params->current_size++;
	}
	if (*n < 0)
	{
		*n *= -1;
		ft_dca_add(str, '-');
		params->current_size++;
	}
	if (!(params->flags & PRECISION) || params->precision < ft_nbrlen(*n))
		return ;
	while (params->precision-- > ft_nbrlen(*n))
	{
		ft_dca_add(str, '0');
		params->current_size++;
	}
}

static void	ft_handle_width(t_params params, int n, t_dca *str)
{
	if (params.width <= ft_nbrlen(n))
		return ;
	params.width -= params.precision;
	params.width -= params.current_size;
	while (params.width-- > ft_nbrlen(n))
	{
		if (params.flags & ZERO && !(params.flags & PRECISION))
			ft_dca_add(str, '0');
		else
			ft_dca_add(str, ' ');
	}
}

static void	ft_handle_number(int n, t_params params, t_dca *str)
{
	char	*nbr;
	if(n == 0 && params.flags & PRECISION && params.precision == 0)
		return ;
	nbr = ft_itoa(n);
	ft_dca_add_str(str, nbr, ft_strlen(nbr));
	free(nbr);
}

void	ft_handle_int(long n, t_params params, t_dca *str)
{
	if (params.flags & PRECISION && params.precision == 0 && n == 0)
	{
		if (params.flags & (PLUS | SPACE))
		{
			if (params.flags & PLUS)
				ft_dca_add(str, '+');
			else
				ft_dca_add(str, ' ');
			if (params.width > 0)
				params.width--;
		}
		while (params.width-- > 0)
			ft_dca_add(str, ' ');
		return ;
	}
	if (params.flags & MINUS)
	{
		ft_handle_persition(&params, &n, str);
		ft_handle_number(n, params, str);
		ft_handle_width(params, n, str);
	}
	else
	{
		ft_handle_width(params, n, str);
		ft_handle_persition(&params, &n, str);
		ft_handle_number(n, params, str);
	}
}
