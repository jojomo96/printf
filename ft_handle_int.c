/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:48:11 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/11 14:37:45 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbr_digits(long n, t_params params)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		if (params.flags & PRECISION && params.original_precision == 0)
		{
			return (0);
		}
		return (1);
	}
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

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
	while (params->precision > 0 && params->precision > ft_nbr_digits(*n,
			*params))
	{
		ft_dca_add(str, '0');
		params->current_size++;
		params->precision--;
	}
}

static void	ft_handle_width(t_params params, long n, t_dca *str)
{
	int	len;

	len = ft_nbr_digits(n, params);
	if (params.width <= len)
		return ;
	params.width -= params.current_size;
	while (params.width-- > len)
	{
		if (params.flags & ZERO && !(params.flags & PRECISION))
			ft_dca_add(str, '0');
		else
			ft_dca_add(str, ' ');
	}
}

static void	ft_handle_number(long n, t_params params, t_dca *str)
{
	char	*nbr;

	if (n == 0 && params.flags & PRECISION)
		return ;
	nbr = ft_itoa(n);
	ft_dca_add_str(str, nbr, ft_strlen(nbr));
	free(nbr);
}

void	ft_handle_int(long n, t_params params, t_dca *str)
{
	if (params.flags & MINUS)
	{
		ft_handle_persition(&params, &n, str);
		ft_handle_number(n, params, str);
		ft_handle_width(params, n, str);
	}
	else
	{
		if (params.flags & ZERO && !(params.flags & PRECISION))
		{
			ft_handle_persition(&params, &n, str);
			ft_handle_width(params, n, str);
		}
		else
		{
			if (params.precision > (ft_nbr_digits(n, params) - 1))
			{
				params.current_size += (params.precision - ft_nbr_digits(n,
							params));
				if (n < 0)
					params.current_size++;
			}
			if (params.flags & (PLUS | SPACE) && n >= 0)
				params.width--;
			ft_handle_width(params, n, str);
			ft_handle_persition(&params, &n, str);
		}
		ft_handle_number(n, params, str);
	}
}
