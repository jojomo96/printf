/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:05:46 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/11 14:02:38 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbr_digits(unsigned long n, t_params params)
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
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	ft_handle_persition(t_params params, unsigned long n, t_dca *str,
		int len)
{
	int i;

	i = 0;
	ft_dca_add(str, '0');
	ft_dca_add(str, 'x');
	while (params.width > len && ((params.flags & ZERO)
				&& !(params.flags & PRECISION)))
		{
			ft_dca_add(str, '0');
			params.width--;
			i++;
		}
	while (params.precision > 0 && params.precision > ft_nbr_digits(n, params))
	{
		ft_dca_add(str, '0');
		params.precision--;
		i++;
	}
	return (i);
}

static int	ft_putnbr_base(unsigned long n, char *base, t_dca *str)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_putnbr_base(n / 16, base, str);
		len += ft_putnbr_base(n % 16, base, str);
	}
	else
	{
		ft_dca_add(str, base[n]);
		len++;
	}
	return (len);
}

void	ft_handle_pointer(unsigned long n, t_params params, t_dca *str)
{
	int	len;

	len = 0;
	if (params.flags & MINUS)
	{
		len += ft_handle_persition(params, n, str, len);
		len += ft_putnbr_base(n, "0123456789abcdef", str) + 2;
		while (params.width > len)
		{
			ft_dca_add(str, ' ');
			params.width--;
		}
	}
	else
	{
		len += ft_nbr_digits(n, params) + 2;
		if (params.precision > ft_nbr_digits(n, params))
			len += params.precision - ft_nbr_digits(n, params);
		while (params.width > len && !((params.flags & ZERO)
				&& !(params.flags & PRECISION)))
		{
			ft_dca_add(str, ' ');
			params.width--;
		}
		ft_handle_persition(params, n, str, len);
		ft_putnbr_base(n, "0123456789abcdef", str);
	}
}
