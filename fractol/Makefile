NAME = fractol
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT_MAKEFILE = libft/Makefile
SRCS =	fractol.c \
		init_frac.c \
		error.c \
		the_fracs.c \
		utils.c \
		event.c
OBJS = ${SRCS:.c=.o}
LIBC = -L./libft -lft
MLXPATH = ./minilibx-linux
MLX = $(MLXPATH)/libmlx.a
LIBFT = ./libft/libft.a

# Rule to create .o files from .c files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Main target
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBC) $(MLX) -L/usr/lib -lXext -lX11 -lm

$(LIBFT):
	@make -C libft

$(MLX):
	@make -C $(MLXPATH)

clean:
	rm -f $(OBJS)
	@make -C libft clean
	@make -C $(MLXPATH) clean

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean
	@rm -f $(MLXPATH)/libmlx.a

re: fclean all

.PHONY: all clean fclean re