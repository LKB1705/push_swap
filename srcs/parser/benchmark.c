/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:19:23 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/12 14:49:34 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* \xc2\xb2 = "2" en exposant, \xe2\x88\x9a = racine carree (UTF-8) */
static char	*strat_label(t_opts o, double d)
{
	if (o.strategy == STRAT_SIMPLE)
		return ("Simple / O(n\xc2\xb2)");
	if (o.strategy == STRAT_MEDIUM)
		return ("Medium / O(n\xe2\x88\x9a" "n)");
	if (o.strategy == STRAT_COMPLEX)
		return ("Complex / O(n log n)");
	if (d < 0.2)
		return ("Adaptive / O(n\xc2\xb2)");
	if (d < 0.5)
		return ("Adaptive / O(n\xe2\x88\x9a" "n)");
	return ("Adaptive / O(n log n)");
}

static void	put_percent(double d)
{
	int	v;

	v = (int)(d * 10000 + 0.5);
	ft_putnbr_fd(v / 100, 2);
	ft_putstr_fd(".", 2);
	if (v % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(v % 100, 2);
	ft_putstr_fd("%", 2);
}

static void	put_counts(t_stats *s, int from, int to)
{
	static char	*names[] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};

	while (from < to)
	{
		ft_putstr_fd(names[from], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(s->ops[from], 2);
		if (++from < to)
			ft_putstr_fd(" ", 2);
	}
}

void	bench(t_opts o, double d, t_stats *s)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < OP_COUNT)
		total += s->ops[i++];
	ft_putstr_fd("[bench] disorder: ", 2);
	put_percent(d);
	ft_putstr_fd("\n[bench] strategy: ", 2);
	ft_putstr_fd(strat_label(o, d), 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n[bench] ", 2);
	put_counts(s, 0, 5);
	ft_putstr_fd("\n[bench] ", 2);
	put_counts(s, 5, OP_COUNT);
	ft_putstr_fd("\n", 2);
}
