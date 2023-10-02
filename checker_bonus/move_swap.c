/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:45:26 by svalente          #+#    #+#             */
/*   Updated: 2023/03/01 14:07:36 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	move_swap(t_stack **head)
{
	t_stack	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
}

void	move_sa(t_stack **stack_a)
{
	move_swap(stack_a);
}

void	move_sb(t_stack **stack_b)
{
	move_swap(stack_b);
}

void	move_ss(t_stack **stack_a, t_stack **stack_b)
{
	move_swap(stack_a);
	move_swap(stack_b);
}
