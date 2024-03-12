/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:46:44 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/12 20:14:40 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_int_number(long n, t_params params, t_dca *str)
{
	char	*nbr;

	if (n == 0 && params.flags & PRECISION)
		return (0);
	nbr = ft_itoa(n);
	if (ft_dca_add_str(str, nbr, ft_strlen(nbr)) == -1)
	{
		return (-1);
	}
	return (0);
}
