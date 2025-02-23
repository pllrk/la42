/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:03:33 by plerick           #+#    #+#             */
/*   Updated: 2025/02/21 16:19:01 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct s_list
{
    int value;
    int index;
    struct s_list *next;
    struct s_list *previous;
} t_list;


// void    init_stack(t_list *stack);
void	fill_stack_a(t_list **a, int argv, int i);
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
void    init_a(char **argv, int argc, t_list **a);
void	add_last(t_list **a, t_list *new_node);

void	sa(t_list **a);
#endif