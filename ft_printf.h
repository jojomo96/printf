/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:54:57 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/11 19:17:26 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dynamic_char_array
{
	char		*data;
	size_t		size;
	size_t		capacity;
}				t_dca;

enum			e_flags
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
	int			flags;
	int			width;
	int			precision;
	int			original_precision;
	int			current_size;
}				t_params;

void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_get_flags(const char **format);
size_t			ft_strlen(const char *s);

char			*ft_itoa(long n);
int				ft_nbrlen(long nbr);

// ft_dynamic_char_array.c
int				ft_dca_init(t_dca *array, size_t initial_capacity);
int				ft_dca_add(t_dca *array, char element);
void			ft_dca_free(t_dca *array);
int				ft_dca_print(t_dca *array);
int				ft_dca_add_str(t_dca *array, const char *str, size_t len);

// ft_bools.c
int				ft_isdigit(int c);
int				ft_is_digit_without_zero(int c);
int				ft_is_valid_format(char c);
int				ft_is_flag(char c);

// ft_estimate_size.c
int				ft_estimate_size(const char *format, ...);

// ft_getters.c
int				ft_get_width(const char **format, va_list args);
int				ft_get_precision(const char **format, va_list args,
					t_params *params);
int				ft_get_flags(const char **format);
int				ft_get_min_len(t_params params);

// ft_handle_format.c
int				ft_handle_format(const char *format, va_list args, t_dca *str);

// ft_printf.c
int				ft_printf(const char *format, ...);
void			ft_handle_char(char c, t_params params, t_dca *str);
void			ft_handle_string(char *s, t_params params, t_dca *str);
void			ft_handle_int(long n, t_params params, t_dca *str);
void			ft_handle_pointer(unsigned long n, t_params params, t_dca *str);
void			ft_handle_hex(long n, t_params params, t_dca *str,
					const char *format);
// int	ft_putnbr_base(unsigned long n, char *base, t_dca *str);
unsigned int	ft_hex_digits(unsigned int n, t_params params);
void			ft_handle_percent(t_params params, t_dca *str);
void			ft_handle_int_number(long n, t_params params, t_dca *str);

#endif
