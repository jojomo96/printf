/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:56:00 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/09 18:28:47 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_dca	*str;

	str = malloc(sizeof(t_dca));
	va_start(args, format);
	ft_dca_init(str, ft_estimate_size(format, args));
	ft_handle_format(format, args, str);
	va_end(args);
	return (ft_dca_print_and_free(str));
}

int main()
{
	printf("%d", ft_printf("Hello, %s!\n", "world"));
	return (0);
}
