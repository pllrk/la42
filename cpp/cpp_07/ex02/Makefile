NAME = Array_T
CC = c++
CFLAGS = -Wall -Werror -Wextra -g -std=c++98
SRCS =	main.cpp
HEADERS = Array.hpp Array.tpp

OBJS = ${SRCS:.cpp=.o}

# Rule to create .o files from .cpp files
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Main target
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all  # Rebuild everything

.PHONY: all clean fclean re