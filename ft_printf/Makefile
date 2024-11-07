NAME = libftprintf.a
LIBFT_DIR = libft
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE
INCLUDE = -I. -I$(LIBFT_DIR)

SRCS = ft_printf.c ft_print_char.c ft_print_string.c ft_print_pointer.c \
       ft_print_integer.c ft_print_unsigned.c ft_print_hex.c ft_print_percent.c
	   
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	@ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re