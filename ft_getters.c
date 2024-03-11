/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:19:02 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/09 19:55:07 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_flags(const char **format)
{
	int	flags;

	flags = 0;
	while (ft_is_flag(**format))
	{
		if (**format == '-')
			flags |= MINUS;
		else if (**format == '0')
			flags |= ZERO;
		else if (**format == '#')
			flags |= HASH;
		else if (**format == ' ')
			flags |= SPACE;
		else if (**format == '+')
			flags |= PLUS;
		(*format)++;
	}
	return (flags);
}

int	ft_get_width(const char **format, va_list args)
{
	int	width;

	width = 0;
	if (**format == '*')
	{
		width = va_arg(args, int);
		(*format)++;
	}
	else
	{
		if (ft_isdigit(**format))
		{
			while (ft_isdigit(**format))
			{
				width = width * 10 + **format - '0';
				(*format)++;
			}
		}
	}
	return (width);
}

int	ft_get_precision(const char **format, va_list args, t_params *params)
{
	int	precision;

	precision = 0;
	if (**format == '.')
	{
		params->flags |= PRECISION;
		(*format)++;
		if (**format == '*')
		{
			precision = va_arg(args, int);
			(*format)++;
		}
		else
		{
			while (ft_isdigit(**format))
			{
				precision = precision * 10 + **format - '0';
				(*format)++;
			}
		}
	}
	return (precision);
}

int	ft_get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_get_min_len(t_params params)
{
	int	min;

	min = params.width;
	if (params.flags & PRECISION && params.precision != 0)
		min = ft_get_min(min, params.precision);
	return (min);
}
