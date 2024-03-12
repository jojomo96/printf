/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_estimate_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:46:39 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/12 20:55:04 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_estimate_size(const char *format, ...)
{
	const char	*p = format;
	int			size;

	size = 0;
	while (*p)
	{
		if (*p == '%')
		{
			p++;
			if (*p == 'd' || *p == 'i' || *p == 'u')
				size += 11;
			else if (*p == 's')
				size += 50;
			else if (*p == 'x' || *p == 'X')
				size += 10;
			else if (*p == 'c')
				size += 1;
			else
				size += 10;
		}
		else
			size += 1;
		p++;
	}
	return (size * 10);
}
