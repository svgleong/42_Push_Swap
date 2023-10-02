/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:46:03 by svalente          #+#    #+#             */
/*   Updated: 2023/03/01 16:40:32 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line/get_next_line.h"
# include "../push_swap.h"

int		ft_strcmp(char *s1, char *s2);
void	move_pa(t_stack **stack_a, t_stack **stack_b);
void	move_pb(t_stack **stack_a, t_stack **stack_b);
void	move_rra(t_stack **stack_a);
void	move_rrb(t_stack **stack_b);
void	move_rrr(t_stack **stack_a, t_stack **stack_b);
void	move_ra(t_stack **stack_a);
void	move_rb(t_stack **stack_b);
void	move_rr(t_stack **stack_a, t_stack **stack_b);
void	move_sa(t_stack **stack_a);
void	move_sb(t_stack **stack_b);
void	move_ss(t_stack **stack_a, t_stack **stack_b);
void	run_moves(char *line, t_stack **stack_a, t_stack **stack_b);
void	checker(t_stack **stack_a, t_stack **stack_b);

#endif