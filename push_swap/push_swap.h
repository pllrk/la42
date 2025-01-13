
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_list;

typedef struct s_stack
{
    t_list *top;
} t_stack;

void    init_stack(t_stack *stack);

#endif