/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:32:32 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/17 12:58:55 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_opts	opts;
	t_stats	s;
	double	disorder;

	opts.strategy = STRAT_NONE;
	opts.bench = 0;
	init_stats(&s);
	a = build_stack(argc, argv, &opts);
	b = NULL;
	disorder = comp_disorder(a);
	choose_methode(opts, &a, &b, &s);
	if (opts.bench)
		bench(opts, disorder, stack_len(a), &s);
	free_stack(&a);
	return (0);
}
