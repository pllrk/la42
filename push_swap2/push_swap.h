/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:03:33 by plerick           #+#    #+#             */
/*   Updated: 2025/02/11 19:36:30 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>

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
void	fill_stack_a(t_stack *stack, int *value);
// void    print_stack(t_stack *stack);
int		calc_array_size(char *argv);
int		check_array_ok(char **array);

int     verif_and_all(int argc, char *argv[]);
int     verif_string(char *argv[]);
int     no_char(char *argv[]);
int	    no_big(char *argv[]);
int		no_double(char *argv[]);
// struct  t_stack push_into_a(argc, argv);
// struct  t_stack with_split(argc, argv);
long 	push_atol(const char *str);
void	*free_all(char **tab, int argc);

#endif