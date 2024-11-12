NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I.libft
LIBFT_MAKEFILE = libft/Makefile
SRCS =	ft_printf.c ft_printchar.c ft_printnbr.c ft_printstr.c ft_printbase_lo.c ft_printbase_up.c ft_printptr.c
OBJS = ${SRCS:.c=.o}
LIBC = -L./libft -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
	@make -C ./libft
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)
	
clean:
	rm -f ${OBJS}
	@make -C libft clean

fclean:	clean
	rm -f ${NAME}
	@make -C libft fclean
	
re:	fclean all

.PHONY: all clean fclean re
