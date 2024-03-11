/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:31:08 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/11 14:16:20 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_specifier(const char **format, va_list args, t_params params,
		t_dca *str)
{
	int is_wrong = 0;

	if (**format == 'c')
		ft_handle_char(va_arg(args, int), params, str);
	else if (**format == 's')
		ft_handle_string(va_arg(args, char *), params, str);
	else if (**format == 'p')
		ft_handle_pointer(va_arg(args, long), params, str);
	else if (**format == 'd' || **format == 'i')
		ft_handle_int(va_arg(args, int), params, str);
	else if (**format == 'u')
		ft_handle_int(va_arg(args, unsigned int), params, str);
	else if (**format == 'x' || **format == 'X')
		ft_handle_hex(va_arg(args, int), params, str, *format);
	else if (**format == '%')
		ft_dca_add(str, '%');
	else
		ft_dca_add(str, **format);
	(*format)++;
}

void	ft_handle_format(const char *format, va_list args, t_dca *str)
{
	t_params	params;

	while (*format)
	{
		if (*format != '%')
		{
			ft_dca_add(str, *format);
			format++;
		}
		else
		{
			format++;
			params.current_size = 0;
			params.flags = ft_get_flags(&format);
			params.width = ft_get_width(&format, args);
			params.precision = ft_get_precision(&format, args, &params);
			params.original_precision = ft_get_precision(&format, args, &params);
			ft_handle_specifier(&format, args, params, str);
		}
	}
}
