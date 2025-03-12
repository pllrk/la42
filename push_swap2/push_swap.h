/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:03:33 by plerick           #+#    #+#             */
/*   Updated: 2025/03/12 18:48:01 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct s_list
{
    int value;
    int index;
    int	push_cost;
	bool	above_median;
	bool	cheapest;
    struct s_list *next;
    struct s_list *previous;
	struct s_list *target_node;	
} t_list;



int		calc_array_size(char *argv);
int		check_array_ok(char **array);

//***  Stack
void    init_a(char **argv, t_list **a);
void	fill_stack_a(t_list **a, int argv, int i);
void	add_last(t_list **a, t_list *new_node);
void	sort_stack(t_list **a, t_list **b);
void	init_nodes_a(t_list *a, t_list *b);
void	current_index(t_list *stack);
static void	set_target_a(t_list *a, t_list *b);
static void	cost_analysis_a(t_list *a, t_list *b);

//*** Check for errors
int     verif_and_all(int argc, char *argv[]);
int     verif_string(char *argv[]);
int     no_char(char *argv[]);
int	    no_big(char *argv[]);
int		no_double(char *argv[]);
long 	push_atol(const char *str);

//*** Commands to free
void	free_split(char **a);
void	free_all(t_list	*stack);

//*** Commands for stack manipulation
void    push(t_list **dst, t_list **src);
void    pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	rev_rotate(t_list **stack);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	rotate(t_list **stack);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	swap(t_list **stack);
void	sa(t_list	**a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

//*** Commands usefull for stack
bool	stack_sorted(t_list *stack);
int		stack_len(t_list *stack);
t_list	*find_big(t_list *stack);
void	sort_three(t_list **a);


#endif