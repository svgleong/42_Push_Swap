/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:56:29 by svalente          #+#    #+#             */
/*   Updated: 2023/02/25 12:40:06 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				content;
	int				half;
	struct s_stack	*next;
}	t_stack;

void	print_list(t_stack *lst); //apagar!!!!

void	op_sa(t_stack **stack_a);
void	op_sb(t_stack **stack_b);
void	op_ss(t_stack **stack_a, t_stack **stack_b);
void	op_pa(t_stack **stack_a, t_stack **stack_b);
void	op_pb(t_stack **stack_a, t_stack **stack_b);
void	op_ra(t_stack **stack_a);
void	op_rb(t_stack **stack_b);
void	op_rr(t_stack **stack_a, t_stack **stack_b);
void	op_rra(t_stack **stack_a);
void	op_rrb(t_stack **stack_b);
void	op_rrr(t_stack **stack_a, t_stack **stack_b);

long	ft_atol(const char *str);
int		ft_atoi(const char *str);
int		check_num(int ac, char **av);
int		check_limits(int ac, char **av);
int		check_dup(int ac, char **av);
int		rules_checker(int ac, char **av);
void	create_list(int ac, char **av, t_stack **list);

t_stack	*new_node(int content);
int		lstsize(t_stack *lst);
void	lstclear(t_stack **lst);

int		find_smallest_int(t_stack **stack);
int		find_next_smallest(int value, t_stack **stack);
int		*create_array(t_stack **stack);
int		find_mid_value(t_stack **stack);
int		value_smallest_int(t_stack **stack);
int		value_at_last(t_stack **stack);
int		check_order(t_stack **stack);
void	sort_3(t_stack **stack_a);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	send_to_b(t_stack **stack_a, t_stack **stack_b);
t_stack	*best_neigh(t_stack *st_a, t_stack *st_b);
int		moves_cost(t_stack **stack, t_stack *elem);
int		best_path(t_stack *st_a, t_stack *st_b, t_stack *elem, t_stack *neigh);
t_stack	*min_cost(t_stack **stack_a, t_stack **stack_b);
void	send_to_a(t_stack **stack_a, t_stack **stack_b);
void	move_lowest_to_top(t_stack **stack_a);
void	sort_long(t_stack **stack_a, t_stack **stack_b);
void	sort_all_numbers(int ac, t_stack **stack_a, t_stack **stack_b);

#endif