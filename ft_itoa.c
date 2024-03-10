/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:39:17 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/10 20:52:04 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Returns the number of digits in the given number.
 *
 * @param nbr The number to be checked.
 * @return The number of digits in the number.
 */
int	ft_nbrlen(long nbr)
{
	int	len;

	len = 1;
	if (nbr > 0)
		len = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

/**
 * Allocates and returns a string representing the integer received as an
 * argument. Negative numbers are handled.
 *
 * @param n The integer to be converted.
 * @return The string representing the integer. NULL if the allocation fails.
 */
char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*str;

	nbr = n;
	len = ft_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr)
	{
		str[--len] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (str);
}
