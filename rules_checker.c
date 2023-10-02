/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:33:29 by svalente          #+#    #+#             */
/*   Updated: 2023/03/03 11:25:20 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
				j++;
			if ((av[i][j] >= '0' && av[i][j] <= '9'))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_limits(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atol(av[i]) == 3737373737)
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	rules_checker(int ac, char **av)
{
	if (ac == 1)
		return (0);
	if (ac != 1)
		if (check_num(ac, av))
			if (check_limits(ac, av))
				if (check_dup(ac, av))
					return (1);
	write(2, "Error\n", 6);
	return (0);
}
