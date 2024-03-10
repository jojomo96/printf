/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:56:00 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/10 18:19:22 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_dca	*str;
	int returnv;

	str = malloc(sizeof(t_dca));
	va_start(args, format);
	ft_dca_init(str, ft_estimate_size(format, args));
	ft_handle_format(format, args, str);
	va_end(args);
	returnv = ft_dca_print(str);
	ft_dca_free(str);
	free(str);
	return (returnv);
}
