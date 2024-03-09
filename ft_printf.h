/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:54:57 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/09 18:17:59 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dynamic_char_array
{
	char	*data;
	size_t	size;
	size_t	capacity;
}			t_dca;

enum		e_flags
{
	MINUS = 1 << 0,
	PLUS = 1 << 1,
	ZERO = 1 << 2,
	HASH = 1 << 3,
	SPACE = 1 << 4
};

void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_recalloc(void *ptr, size_t old_size, size_t new_size);
void		*ft_calloc(size_t count, size_t size);

// ft_dynamic_char_array.c
int			ft_dca_init(t_dca *array, size_t initial_capacity);
int			ft_dca_add(t_dca *array, char element);
void		ft_dca_free(t_dca *array);
int			ft_dca_print(t_dca *array);
int			ft_dca_print_and_free(t_dca *array);

// ft_bools.c
int			ft_isdigit(int c);
int			ft_is_digit_without_zero(int c);
int			ft_is_valid_format(char c);
int			ft_is_flag(char c);

// ft_estimate_size.c
int			ft_estimate_size(const char *format, ...);

#endif
