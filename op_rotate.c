/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:35:12 by svalente          #+#    #+#             */
/*   Updated: 2023/02/25 12:04:04 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_rotate(t_stack **head)
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

void	op_ra(t_stack **stack_a)
{
	op_rotate(stack_a);
	ft_printf("ra\n");
}

void	op_rb(t_stack **stack_b)
{
	op_rotate(stack_b);
	ft_printf("rb\n");
}

void	op_rr(t_stack **stack_a, t_stack **stack_b)
{
	op_rotate(stack_a);
	op_rotate(stack_b);
	ft_printf("rr\n");
}
