/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:31:08 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/09 20:12:31 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_char(char c, t_params *params, t_dca *str)
{
	if (params->flags & MINUS)
		ft_dca_add(str, c);
	while (params->width > 1)
	{
		ft_dca_add(str, ' ');
		params->width--;
	}
	if (!(params->flags & MINUS))
		ft_dca_add(str, c);
}

void	ft_handle_format(const char *format, va_list args, t_dca *str)
{
	t_params	params;

	params.flags = ft_get_flags(format);
	params.width = ft_get_width(format, args);
	params.precision = ft_get_precision(format, args);

	if (*format == 'c')
		ft_handle_char(va_arg(args, char), &params, str);
	else if (*format == 's')
		ft_handle_string(args, &params, str);
	else if (*format == 'p')
		ft_handle_pointer(args, &params, str);
	else if (*format == 'd' || *format == 'i')
		ft_handle_int(args, &params, str);
	else if (*format == 'u')
		ft_handle_unsigned_int(args, &params, str);
	else if (*format == 'x' || *format == 'X')
		ft_handle_hex(args, &params, str, *format);
	else if (*format == '%')
		ft_handle_percent(&params, str);

}
