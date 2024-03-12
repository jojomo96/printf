# Compiler
CC := cc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# Library name
NAME := libftprintf.a

# Source files
SRCS := ft_printf.c \
		ft_bools.c \
		ft_handle_char.c \
		ft_getters.c \
		ft_dynamic_char_array.c \
		ft_calloc.c \
		ft_estimate_size.c \
		ft_handle_format.c \
		ft_memcpy.c \
		ft_handle_string.c \
		ft_strlen.c \
		ft_handle_int.c \
		ft_itoa.c \
		ft_handle_pointer.c \
		ft_handle_hex.c \
		ft_hex_helper.c \
		ft_handle_percent.c \
		ft_int_helper.c \

# Object files
OBJS := $(SRCS:.c=.o)

# Build rule
all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

# Clean and remove library rule
fclean: clean
	rm -f $(NAME)

# Rebuild rule
re: fclean all

.PHONY: all clean fclean re bonus
