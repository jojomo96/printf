/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:54:57 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/10 18:12:57 by jmoritz          ###   ########.fr       */
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
	SPACE = 1 << 4,
	PRECISION = 1 << 5,
};

typedef struct s_params
{
	int		flags;
	int		width;
	int		precision;
}			t_params;

void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_recalloc(void *ptr, size_t old_size, size_t new_size);
void		*ft_calloc(size_t count, size_t size);
int			ft_get_flags(const char **format);

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

// ft_getters.c
int			ft_get_width(const char **format, va_list args);
int			ft_get_precision(const char **format, va_list args,
				t_params *params);
int			ft_get_flags(const char **format);
int			ft_get_min(int a, int b);

// ft_handle_format.c
void		ft_handle_format(const char *format, va_list args, t_dca *str);

// ft_printf.c
int			ft_printf(const char *format, ...);
void		ft_handle_char(char c, t_params params, t_dca *str);

#endif
