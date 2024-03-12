/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:39:17 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/12 20:19:40 by jmoritz          ###   ########.fr       */
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

	len = 0;
	if (nbr <= 0)
	{
		len = 1;
		nbr = -nbr;
	}
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
void	reverse_str(char *str, int length)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

void	ft_do_negative(long *n, int *is_negative)
{
	if (*n < 0)
	{
		*is_negative = 1;
		*n = -(*n);
	}
}

// Convert long to string without dynamic memory allocation
char	*ft_itoa(long n)
{
	static char	str[BUFFER_SIZE];
	int			i;
	int			is_negative;
	long		temp_n;

	i = 0;
	temp_n = n;
	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	is_negative = 0;
	ft_do_negative(&temp_n, &is_negative);
	while (temp_n != 0 && i < BUFFER_SIZE - 2)
	{
		str[i++] = (temp_n % 10) + '0';
		temp_n /= 10;
	}
	if (is_negative)
		str[i++] = '-';
	str[i] = '\0';
	reverse_str(str, i);
	return (str);
}
