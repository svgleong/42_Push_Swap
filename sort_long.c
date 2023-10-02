/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:15:49 by svalente          #+#    #+#             */
/*   Updated: 2023/02/25 12:30:53 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_long(t_stack **stack_a, t_stack **stack_b)
{
	send_to_b(stack_a, stack_b);
	while (lstsize(*stack_b) > 0)
		send_to_a(stack_a, stack_b);
	move_lowest_to_top(stack_a);
}

void	send_to_b(t_stack **stack_a, t_stack **stack_b)
{
	while (lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->content < find_mid_value(stack_a))
			op_pb(stack_a, stack_b);
		else
			op_ra(stack_a);
	}
	if (check_order(stack_a) == 0)
		sort_3(stack_a);
}

t_stack	*min_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		min_cost;
	int		cost;
	t_stack	*neigh;
	t_stack	*elem;
	t_stack	*temp;

	min_cost = INT_MAX;
	elem = *stack_b;
	temp = *stack_b;
	while (temp)
	{
		neigh = best_neigh(*stack_a, temp);
		cost = best_path(*stack_a, *stack_b, temp, neigh);
		if (cost < min_cost)
		{
			min_cost = cost;
			elem = temp;
		}
		temp = temp->next;
	}
	return (elem);
}

static int	half(t_stack **stack, t_stack *elem)
{
	if (lstsize(elem) > lstsize(*stack) / 2)
		return (0);
	else
		return (1);
}

void	move_lowest_to_top(t_stack **stack_a)
{
	int		i;
	t_stack	*temp;

	i = value_smallest_int(stack_a);
	temp = *stack_a;
	while (temp)
	{
		if (temp->content == i)
			break ;
		temp = temp->next;
	}
	if (half(stack_a, temp) == 0)
	{
		while ((*stack_a)->content != i)
			op_ra(stack_a);
	}
	else if (half(stack_a, temp) == 1)
	{
		while ((*stack_a)->content != i)
			op_rra(stack_a);
	}
}
