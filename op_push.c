/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:29:57 by svalente          #+#    #+#             */
/*   Updated: 2023/02/25 12:01:32 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_push(t_stack **head1, t_stack **head2)
{
	t_stack	*temp;

	if (*head2 == NULL)
		return ;
	temp = *head2;
	*head2 = (*head2)->next;
	temp->next = *head1;
	*head1 = temp;
}

void	op_pa(t_stack **stack_a, t_stack **stack_b)
{
	op_push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	op_pb(t_stack **stack_a, t_stack **stack_b)
{
	op_push(stack_b, stack_a);
	ft_printf("pb\n");
}
