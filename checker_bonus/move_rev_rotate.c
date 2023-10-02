/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:37:05 by svalente          #+#    #+#             */
/*   Updated: 2023/03/01 18:10:19 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	move_rev_rotate(t_stack **head)
{
	t_stack	*temp;

	temp = *head;
	while ((*head)->next)
		*head = (*head)->next;
	(*head)->next = temp;
	while (temp->next != *head)
		temp = temp->next;
	temp->next = NULL;
}

void	move_rra(t_stack **stack_a)
{
	move_rev_rotate(stack_a);
}

void	move_rrb(t_stack **stack_b)
{
	move_rev_rotate(stack_b);
}

void	move_rrr(t_stack **stack_a, t_stack **stack_b)
{
	move_rev_rotate(stack_a);
	move_rev_rotate(stack_b);
}
