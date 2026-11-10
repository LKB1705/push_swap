/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:32:32 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/06 12:33:21 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_node	*node;
	t_opts	opts;

	opts.strategy = STRAT_NONE;
	opts.bench = 0;
	a = build_stack(argc, argv, &opts);
	b = NULL;
	ft_printf("strat=%d bench=%d | pile a :", opts.strategy, opts.bench);
	node = a;
	while (node)
	{
		ft_printf(" %d", node->value);
		node = node->next;
	}
	ft_printf("\n");
	turk(&a, &b);
	free_stack(&a);
	return (0);
}
