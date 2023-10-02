/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:23:35 by svalente          #+#    #+#             */
/*   Updated: 2023/02/16 11:31:37 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_sa_rra(t_stack **stack_a);
static void	op_sa_ra(t_stack **stack_a);

void	sort_3(t_stack **stack_a)
{
	int	nb_1;
	int	nb_2;
	int	nb_3;

	nb_1 = (*stack_a)->content;
	nb_2 = (*stack_a)->next->content;
	nb_3 = (*stack_a)->next->next->content;
	if (nb_1 > nb_2 && nb_1 < nb_3)
		op_sa(stack_a);
	else if (nb_1 > nb_2 && nb_2 > nb_3)
		op_sa_rra(stack_a);
	else if (nb_1 > nb_3 && nb_2 < nb_3)
		op_ra(stack_a);
	else if (nb_1 < nb_2 && nb_2 > nb_3 && nb_1 < nb_3)
		op_sa_ra(stack_a);
	else if (nb_1 > nb_3 && nb_1 < nb_2)
		op_rra(stack_a);
}

static void	op_sa_rra(t_stack **stack_a)
{
	op_sa(stack_a);
	op_rra(stack_a);
}

static void	op_sa_ra(t_stack **stack_a)
{
	op_sa(stack_a);
	op_ra(stack_a);
}
