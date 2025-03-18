NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT_MAKEFILE = libft/Makefile
ALGO_DIR = algo/
COM_DIR = commands/
VERIF_DIR = verifications/
SRCS = push_swap.c \
       $(VERIF_DIR)push_atol.c \
       $(VERIF_DIR)verif_and_all.c \
       $(VERIF_DIR)verif_string.c \
       $(COM_DIR)push.c \
       $(COM_DIR)rev_rotate.c \
       $(COM_DIR)rotate.c \
       $(COM_DIR)swap.c \
       $(ALGO_DIR)init_a_to_b.c \
       $(ALGO_DIR)init_b_to_a.c \
       $(ALGO_DIR)sort_stack.c \
       $(ALGO_DIR)sort_three.c \
       $(ALGO_DIR)stack_utils.c

OBJS = ${SRCS:.c=.o}
LIBC = -L./libft -lft

# Rule to create .o files from .c files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Main target
all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft  # Compile libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBC)  # Link the object files to create the final binary

clean:
	rm -f ${OBJS}
	@make -C libft clean  # Clean libft

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean  # Fully clean libft

re: fclean all  # Rebuild everything

.PHONY: all clean fclean re
