/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:56:00 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/09 18:14:14 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_dca	*str;

	va_start(args, format);
	ft_dca_init(str, ft_estimate_size(format, args));
	va_end(args);
	return (ft_dca_print_and_free(str));
}
