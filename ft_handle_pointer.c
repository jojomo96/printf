/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:05:46 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/12 20:48:57 by jmoritz          ###   ########.fr       */
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
	int	i;

	i = 0;
	if (ft_dca_add_str(str, "0x", 2) == -1)
		return (-1);
	while (params.width > len && ((params.flags & ZERO)
			&& !(params.flags & PRECISION)))
	{
		if (ft_dca_add(str, '0') == -1)
			return (-1);
		params.width--;
		i++;
	}
	while (params.precision > 0 && params.precision > ft_nbr_digits(n, params))
	{
		if (ft_dca_add(str, '0') == -1)
			return (-1);
		params.precision--;
		i++;
	}
	return (i);
}

static int	ft_putnbr_base(unsigned long n, char *base, t_dca *str)
{
	int	len;
	int	temp_len;

	len = 0;
	if (n >= 16)
	{
		temp_len = ft_putnbr_base(n / 16, base, str);
		if (temp_len == -1)
			return (-1);
		len += temp_len;
		temp_len = ft_putnbr_base(n % 16, base, str);
		if (temp_len == -1)
			return (-1);
		len += temp_len;
	}
	else
	{
		if (ft_dca_add(str, base[n]) == -1)
			return (-1);
		len++;
	}
	return (len);
}

static int	ft_do_without_minus(t_params params, unsigned long n, t_dca *str)
{
	int	len;

	len = 0;
	len += ft_nbr_digits(n, params) + 2;
	if (params.precision > ft_nbr_digits(n, params))
		len += params.precision - ft_nbr_digits(n, params);
	while (params.width > len && !((params.flags & ZERO)
			&& !(params.flags & PRECISION)))
	{
		if (ft_dca_add(str, ' ') == -1)
			return (-1);
		params.width--;
	}
	if (ft_handle_persition(params, n, str, len) == -1)
		return (-1);
	if (ft_putnbr_base(n, "0123456789abcdef", str) == -1)
		return (-1);
	return (0);
}

int	ft_handle_pointer(unsigned long n, t_params params, t_dca *str)
{
	int	len;
	int	temp_len;

	len = 0;
	if (params.flags & MINUS)
	{
		temp_len = ft_handle_persition(params, n, str, len);
		if (temp_len == -1)
			return (-1);
		len += temp_len;
		temp_len = ft_putnbr_base(n, "0123456789abcdef", str) + 2;
		if (temp_len == -1)
			return (-1);
		len += temp_len;
		while (params.width > len)
		{
			if (ft_dca_add(str, ' ') == -1)
				return (-1);
			params.width--;
		}
	}
	else if (ft_do_without_minus(params, n, str) == -1)
		return (-1);
	return (0);
}
