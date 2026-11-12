/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedal <lfedal@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:20:00 by lfedal            #+#    #+#             */
/*   Updated: 2026/11/12 11:20:00 by lfedal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	add_token(t_node **a, char *tok, int idx)
{
	t_node	*node;
	int		value;

	if (!is_valid_number(tok) || !str_to_int(tok, &value))
		return (0);
	if (is_double(*a, value))
		return (0);
	node = ft_lstnew(value, idx, a);
	if (!node)
		return (0);
	ft_lstadd_back(a, node);
	return (1);
}

static int	parse_arg(t_node **a, char *arg, int *pos)
{
	char	**tab;
	int		j;

	tab = ft_split(arg, ' ');
	if (!tab)
		return (0);
	if (!tab[0])
	{
		free_split(tab);
		return (0);
	}
	j = 0;
	while (tab[j])
	{
		if (!add_token(a, tab[j], (*pos)++))
		{
			free_split(tab);
			return (0);
		}
		j++;
	}
	free_split(tab);
	return (1);
}

t_node	*build_stack(int argc, char **argv, t_opts *opts)
{
	t_node	*a;
	int		i;
	int		pos;

	a = NULL;
	pos = 0;
	opts->bench = 0;
	opts->strategy = STRAT_NONE;
	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			if (!parse_flag(argv[i], opts))
				error_exit(&a);
		}
		else if (!parse_arg(&a, argv[i], &pos))
			error_exit(&a);
		i++;
	}
	if (opts->strategy == STRAT_NONE)
		opts->strategy = STRAT_ADAPTIVE;
	return (a);
}
