NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT_MAKEFILE = libft/Makefile 
SRCS =	push_swap.c calc_array_size.c check_array_ok.c print_stack.c push_atoi.c
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
