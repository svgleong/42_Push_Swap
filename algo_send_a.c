/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_send_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:19:22 by svalente          #+#    #+#             */
/*   Updated: 2023/02/25 12:25:29 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	all_upper_half(t_stack **stack_a, t_stack **stack_b);
static void	all_lower_half(t_stack **stack_a, t_stack **stack_b);
static void	upper_half(t_stack **stack_a, t_stack **stack_b, char stack);
static void	lower_half(t_stack **stack_a, t_stack **stack_b, char stack);

void	send_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*elem;
	t_stack	*best;

	elem = min_cost(stack_a, stack_b);
	best = best_neigh(*stack_a, elem);
	if (best->half == 0 && elem->half == 0)
		all_upper_half(stack_a, stack_b);
	else if (best->half == 1 && elem->half == 1)
		all_lower_half(stack_a, stack_b);
	else if (best->half == 1 && elem->half == 0)
	{
		lower_half(stack_a, stack_b, 'a');
		upper_half(stack_a, stack_b, 'b');
	}
	else if (best->half == 0 && elem->half == 1)
	{
		upper_half(stack_a, stack_b, 'a');
		lower_half(stack_a, stack_b, 'b');
	}
	op_pa(stack_a, stack_b);
}

static void	all_upper_half(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*elem;
	t_stack	*best;
	int		cost_a;
	int		cost_b;

	elem = min_cost(stack_a, stack_b);
	best = best_neigh(*stack_a, elem);
	cost_a = moves_cost(stack_a, best);
	cost_b = moves_cost(stack_b, elem);
	while (cost_a > 0 && cost_b > 0)
	{
		op_rr(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
	if (cost_a > 0)
		while (cost_a-- > 0)
			op_ra(stack_a);
	else if (cost_b > 0)
		while (cost_b-- > 0)
			op_rb(stack_b);
}

static void	all_lower_half(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*elem;
	t_stack	*best;
	int		cost_a;
	int		cost_b;

	elem = min_cost(stack_a, stack_b);
	best = best_neigh(*stack_a, elem);
	cost_a = moves_cost(stack_a, best);
	cost_b = moves_cost(stack_b, elem);
	while (cost_a > 0 && cost_b > 0)
	{
		op_rrr(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
	if (cost_a > 0)
		while (cost_a-- > 0)
			op_rra(stack_a);
	else if (cost_b > 0)
		while (cost_b-- > 0)
			op_rrb(stack_b);
}

static void	upper_half(t_stack **stack_a, t_stack **stack_b, char stack)
{
	t_stack	*elem;
	t_stack	*best;
	int		cost_a;
	int		cost_b;

	elem = min_cost(stack_a, stack_b);
	best = best_neigh(*stack_a, elem);
	cost_a = moves_cost(stack_a, best);
	cost_b = moves_cost(stack_b, elem);
	if (stack == 'a')
	{
		while (cost_a-- > 0)
			op_ra(stack_a);
	}
	if (stack == 'b')
	{
		while (cost_b-- > 0)
			op_rb(stack_b);
	}
}

static void	lower_half(t_stack **stack_a, t_stack **stack_b, char stack)
{
	t_stack	*elem;
	t_stack	*best;
	int		cost_a;
	int		cost_b;

	elem = min_cost(stack_a, stack_b);
	best = best_neigh(*stack_a, elem);
	cost_a = moves_cost(stack_a, best);
	cost_b = moves_cost(stack_b, elem);
	if (stack == 'a')
	{
		while (cost_a-- > 0)
			op_rra(stack_a);
	}
	if (stack == 'b')
	{
		while (cost_b-- > 0)
			op_rrb(stack_b);
	}
}
