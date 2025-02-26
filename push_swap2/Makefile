NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT_MAKEFILE = libft/Makefile 
SRCS =	push_swap.c push_atol.c verif_and_all.c verif_string.c push_into_a.c with_split.c commandes.c
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
