/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:48:11 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/12 20:22:13 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_persition(t_params *params, long *n, t_dca *str,
		const char *format)
{
	if (params->flags & HASH && *n != 0)
	{
		ft_dca_add(str, '0');
		ft_dca_add(str, *format);
	}
	while (params->precision > 0 && (unsigned int)params->precision > ft_hex_digits(*n,
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

	len = ft_hex_digits(n, params);
	if (params.flags & HASH && n != 0)
		len += 2;
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

static void	ft_putnbr_base(unsigned int n, char *base, t_dca *str)
{
	if (n >= 16)
	{
		ft_putnbr_base(n / 16, base, str);
		ft_putnbr_base(n % 16, base, str);
	}
	else
		ft_dca_add(str, base[n]);
}

static void	ft_handle_number(long n, t_params params, t_dca *str,
		const char *format)
{
	if (n == 0 && params.flags & PRECISION)
		return ;
	if (*format == 'x')
		ft_putnbr_base(n, "0123456789abcdef", str);
	else
		ft_putnbr_base(n, "0123456789ABCDEF", str);
}

void	ft_handle_hex(long n, t_params params, t_dca *str, const char *format)
{
	if (params.flags & MINUS)
	{
		ft_handle_persition(&params, &n, str, format);
		ft_handle_number(n, params, str, format);
		ft_handle_width(params, n, str);
	}
	else
	{
		if (params.flags & ZERO && !(params.flags & PRECISION))
		{
			ft_handle_persition(&params, &n, str, format);
			ft_handle_width(params, n, str);
		}
		else
		{
			if ((unsigned int)params.precision > (ft_hex_digits(n, params)))
			{
				params.current_size += (params.precision - ft_hex_digits(n,
							params));
			}
			ft_handle_width(params, n, str);
			ft_handle_persition(&params, &n, str, format);
		}
		ft_handle_number(n, params, str, format);
	}
}
