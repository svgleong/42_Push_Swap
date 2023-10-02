/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:45:35 by svalente          #+#    #+#             */
/*   Updated: 2023/02/25 12:38:25 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_smallest_of_5(t_stack **stack_a, t_stack **stack_b);
static void	move_smallest_of_4(t_stack **stack_a, t_stack **stack_b);

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = lstsize(*stack_a);
	if (check_order(stack_a) == 0)
	{
		if (lstsize(*stack_a) == 5)
			move_smallest_of_5(stack_a, stack_b);
		if (lstsize(*stack_a) == 4)
			move_smallest_of_4(stack_a, stack_b);
		if (check_order(stack_a) == 0)
			sort_3(stack_a);
		if (size == 5)
			op_pa(stack_a, stack_b);
		op_pa(stack_a, stack_b);
	}
}

static void	move_smallest_of_5(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = find_smallest_int(stack_a);
	if (i <= 2)
		while (i-- > 0)
			op_ra(stack_a);
	else
		while (i++ <= 4)
			op_rra(stack_a);
	op_pb(stack_a, stack_b);
}

static void	move_smallest_of_4(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = find_smallest_int(stack_a);
	if (i == 1)
		op_ra(stack_a);
	else if (i > 1)
		while (i++ <= 3)
			op_rra(stack_a);
	op_pb(stack_a, stack_b);
}
