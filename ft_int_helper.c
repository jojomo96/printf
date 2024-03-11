/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:46:44 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/11 16:49:29 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_int_number(long n, t_params params, t_dca *str)
{
	char	*nbr;

	if (n == 0 && params.flags & PRECISION)
		return ;
	nbr = ft_itoa(n);
	if (nbr == NULL)
		return ;
	ft_dca_add_str(str, nbr, ft_strlen(nbr));
	free(nbr);
}
