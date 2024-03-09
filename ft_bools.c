/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:13:26 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/09 17:23:22 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_is_digit_without_zero(int c)
{
	return ('1' <= c && c <= '9');
}

int	ft_is_valid_format(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

int	ft_is_flag(char c)
{
	return (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+');
}
