/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:42:15 by svalente          #+#    #+#             */
/*   Updated: 2023/03/01 13:43:36 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	move_rotate(t_stack **head)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = *head;
	*head = (*head)->next;
	temp2 = *head;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = temp1;
	temp1->next = NULL;
}

void	move_ra(t_stack **stack_a)
{
	move_rotate(stack_a);
}

void	move_rb(t_stack **stack_b)
{
	move_rotate(stack_b);
}

void	move_rr(t_stack **stack_a, t_stack **stack_b)
{
	move_rotate(stack_a);
	move_rotate(stack_b);
}
