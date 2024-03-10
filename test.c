/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:07:17 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/10 19:46:07 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// printf("%.3s", "123456");

	// printf("|%d\n",printf("%-010.5s", "123", "", "4", ""));
	printf("|%d\n",printf("%10.2s", "123"));
	printf("|%d\n",ft_printf("%10.2s", "123"));

	printf("|%d\n",printf("%10.1s", "123"));
	printf("|%d\n",ft_printf("%10.1s", "123"));

	printf("|%d\n",printf("%-8.s", NULL));
	printf("|%d\n",ft_printf("%-8.s", NULL));
	// ft_printf("Hello, %%! %5c %c\n", 'a', 'b');
	return (0);
}
