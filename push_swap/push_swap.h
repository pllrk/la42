
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
    struct s_node *previous;
} t_list;

typedef struct s_stack
{
    t_list *top;
} t_stack;

void    init_stack(t_stack *stack);
void	fill_stack_a(t_stack *stack, int value);
void    print_stack(t_stack *stack);

#endif