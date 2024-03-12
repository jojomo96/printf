/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:31:08 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/12 20:54:34 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_specifier(const char **format, va_list args, t_params params,
		t_dca *str)
{
	int	is_wrong;

	is_wrong = 0;
	if (**format == 'c')
		ft_handle_char(va_arg(args, int), params, str);
	else if (**format == 's')
		ft_handle_string(va_arg(args, char *), params, str);
	else if (**format == 'p')
		ft_handle_pointer(va_arg(args, long), params, str);
	else if (**format == 'd' || **format == 'i')
	{
		if (ft_handle_int(va_arg(args, int), params, str) == -1)
			return (-1);
	}
	else if (**format == 'u')
		ft_handle_int(va_arg(args, unsigned int), params, str);
	else if (**format == 'x' || **format == 'X')
		ft_handle_hex(va_arg(args, int), params, str, *format);
	else if (**format == '%')
		ft_handle_percent(params, str);
	else
		ft_dca_add(str, **format);
	(*format)++;
	return (0);
}

int	ft_handle_format(const char *format, va_list args, t_dca *str)
{
	t_params	params;

	while (*format)
	{
		if (*format != '%')
		{
			if (ft_dca_add(str, *format) == -1)
				return (-1);
			format++;
		}
		else
		{
			format++;
			params.current_size = 0;
			params.flags = ft_get_flags(&format);
			params.width = ft_get_width(&format, args);
			params.precision = ft_get_precision(&format, args, &params);
			params.original_precision = ft_get_precision(&format, args,
					&params);
			if (ft_handle_specifier(&format, args, params, str) == -1)
				return (-1);
		}
	}
	return (0);
}
