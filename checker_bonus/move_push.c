/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:28:53 by svalente          #+#    #+#             */
/*   Updated: 2023/03/03 11:30:04 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	move_push(t_stack **head1, t_stack **head2)
{
	t_stack	*temp;

	if (!(*head2))
		return ;
	temp = *head2;
	*head2 = (*head2)->next;
	temp->next = *head1;
	*head1 = temp;
}

void	move_pa(t_stack **stack_a, t_stack **stack_b)
{
	move_push(stack_a, stack_b);
}

void	move_pb(t_stack **stack_a, t_stack **stack_b)
{
	move_push(stack_b, stack_a);
}
