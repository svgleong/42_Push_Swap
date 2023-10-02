/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:58:54 by svalente          #+#    #+#             */
/*   Updated: 2023/02/25 12:38:34 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_all_numbers(int ac, t_stack **stack_a, t_stack **stack_b)
{
	if (ac == 3 && check_order(stack_a) == 0)
		op_sa(stack_a);
	else if (ac == 4 && check_order(stack_a) == 0)
		sort_3(stack_a);
	else if (ac == 5 || ac == 6)
		sort_5(stack_a, stack_b);
	else if (ac > 6 && check_order(stack_a) == 0)
		sort_long(stack_a, stack_b);
}

int	check_order(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}
