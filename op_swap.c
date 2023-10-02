/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:36:51 by svalente          #+#    #+#             */
/*   Updated: 2023/02/25 12:04:26 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_swap(t_stack **head)
{
	t_stack	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
}

void	op_sa(t_stack **stack_a)
{
	op_swap(stack_a);
	ft_printf("sa\n");
}

void	op_sb(t_stack **stack_b)
{
	op_swap(stack_b);
	ft_printf("sb\n");
}

void	op_ss(t_stack **stack_a, t_stack **stack_b)
{
	op_swap(stack_a);
	op_swap(stack_b);
	ft_printf("ss\n");
}
