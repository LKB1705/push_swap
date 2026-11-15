/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedal <lfedal@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:20:04 by oracio            #+#    #+#             */
/*   Updated: 2026/11/15 22:18:59 by lfedal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_methode(t_opts strat, t_node **a, t_node **b, t_stats *s)
{
	double	disorder;

	disorder = comp_disorder(*a);
	if (disorder == 0)
		return ;
	if (strat.strategy == STRAT_ADAPTIVE)
	{
		if (disorder < 0.2)
			turk(a, b, s);
		else if (disorder >= 0.2 && disorder < 0.5)
			chunk_sort(a, b, s);
		else if (disorder >= 0.5)
			radix(a, b, s);
	}
	else
	{
		if (strat.strategy == STRAT_SIMPLE)
			turk(a, b, s);
		else if (strat.strategy == STRAT_MEDIUM)
			chunk_sort(a, b, s);
		else if (strat.strategy == STRAT_COMPLEX)
			radix(a, b, s);
	}
}

/*t_node	*create_stack_a(int argc, char **argv)
{
	int		i;
	int		value;
	t_node	*stack_a;
	t_node	*stack_n;

	if (argc < 2)
		return (NULL);
	stack_a = NULL;
	i = 1;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		stack_n = ft_lstnew(value, i, &stack_a);
		if (!stack_n)
			return (NULL);
		ft_lstadd_back(&stack_a, stack_n);
		i++;
	}
	return (stack_a);
}*/