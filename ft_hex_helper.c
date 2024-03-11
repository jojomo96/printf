/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:32:13 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/11 14:46:10 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_hex_digits_helper(unsigned int n, t_params params)
{
	unsigned int	count;

	count = 0;

	if (n >= 16)
	{
		count += ft_hex_digits_helper(n / 16, params);
		count += ft_hex_digits_helper(n % 16, params);
	}
	else
	{
		count = 1;
	}
	return (count);
}


unsigned int	ft_hex_digits(unsigned int n, t_params params)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
	{
		if (params.flags & PRECISION && params.original_precision == 0)
		{
			return (0);
		}
		return (1);
	}
	count = ft_hex_digits_helper(n, params);
	return (count);
}
