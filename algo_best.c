/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:26:42 by svalente          #+#    #+#             */
/*   Updated: 2023/03/03 11:22:19 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	subtract(double a, double b);
static int		bigger(int cost_a, int cost_b);

t_stack	*best_neigh(t_stack *st_a, t_stack *st_b)
{
	t_stack	*neigh;
	double	diff;

	neigh = st_a;
	diff = 8294967300;
	while (st_a)
	{
		if (subtract(st_a->content, st_b->content) < diff
			&& st_a->content > st_b->content)
		{
			neigh = st_a;
			diff = subtract(st_a->content, st_b->content);
		}
		st_a = st_a->next;
	}
	return (neigh);
}

static double	subtract(double a, double b)
{
	double	value;

	if (a >= b)
		value = a - b;
	else
		value = b - a;
	return (value);
}

int	best_path(t_stack *st_a, t_stack *st_b, t_stack *elem, t_stack *neigh)
{
	int	cost_a;
	int	cost_b;

	cost_a = moves_cost(&st_a, neigh);
	cost_b = moves_cost(&st_b, elem);
	if (neigh->half == 0 && elem->half == 0)
		return (bigger(cost_a, cost_b));
	if (neigh->half == 1 && elem->half == 1)
		return (bigger(cost_a, cost_b));
	else
		return (cost_a + cost_b);
}

int	moves_cost(t_stack **stack, t_stack *elem)
{
	if (lstsize(elem) > lstsize(*stack) / 2)
	{
		elem->half = 0;
		return (lstsize(*stack) - lstsize(elem));
	}
	else
	{
		elem->half = 1;
		return (lstsize(elem));
	}
}

static int	bigger(int cost_a, int cost_b)
{
	if (cost_a >= cost_b)
		return (cost_a);
	else
		return (cost_b);
}
