/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:45:10 by svalente          #+#    #+#             */
/*   Updated: 2023/03/01 18:10:53 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (rules_checker(ac, av) == 0)
		return (0);
	create_list(ac, av, &stack_a);
	checker(&stack_a, &stack_b);
	if (check_order(&stack_a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	lstclear(&stack_a);
	lstclear(&stack_b);
}

void	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		run_moves(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

void	run_moves(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "pa\n") == 1)
		move_pa(stack_a, stack_b);
	if (ft_strcmp(line, "pb\n") == 1)
		move_pb(stack_a, stack_b);
	if (ft_strcmp(line, "rra\n") == 1)
		move_rra(stack_a);
	if (ft_strcmp(line, "rrb\n") == 1)
		move_rrb(stack_b);
	if (ft_strcmp(line, "rrr\n") == 1)
		move_rrr(stack_a, stack_b);
	if (ft_strcmp(line, "ra\n") == 1)
		move_ra(stack_a);
	if (ft_strcmp(line, "rb\n") == 1)
		move_rb(stack_b);
	if (ft_strcmp(line, "rr\n") == 1)
		move_rr(stack_a, stack_b);
	if (ft_strcmp(line, "sa\n") == 1)
		move_sa(stack_a);
	if (ft_strcmp(line, "sb\n") == 1)
		move_sb(stack_b);
	if (ft_strcmp(line, "ss\n") == 1)
		move_ss(stack_a, stack_b);
}
