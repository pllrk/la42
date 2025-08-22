NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
# LIBFT_MAKEFILE = libft/Makefile
#PARSING_DIR = parsing/
SRCS = 	main.c \
		ft_atol.c \
		utils.c \
		utils2.c \
		fork_and_philo.c \
		task.c \

OBJS = ${SRCS:.c=.o}
# LIBC = -L./libft -lft -lreadline

# Rule to create .o files from .c files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Main target
all: $(NAME)

$(NAME): $(OBJS)
#	@make -C libft  # Compile libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)  # Link the object files to create the final binary

clean:
	rm -f ${OBJS}
#	@make -C libft clean  # Clean libft

fclean: clean
	rm -f $(NAME)
#	@make -C libft fclean  # Fully clean libft

re: fclean all  # Rebuild everything

.PHONY: all clean fclean re
