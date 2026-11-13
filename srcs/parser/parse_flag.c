/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedal <lfedal@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 15:50:05 by lfedal            #+#    #+#             */
/*   Updated: 2026/11/10 15:05:00 by lfedal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] == s1[i])
		i++;
	return (s1[i] - s2[i]);
}

int	is_flag(char *s)
{
	if (s[0] == '-' && s[1] == '-')
		return (1);
	return (0);
}

int	parse_flag(char *s, t_opts *opts)
{
	int	strat;

	if (ft_strcmp(s, "--bench") == 0)
	{
		if (opts->bench == 1)
			return (0);
		opts->bench = 1;
		return (1);
	}
	if (ft_strcmp(s, "--simple") == 0)
		strat = STRAT_SIMPLE;
	else if (ft_strcmp(s, "--medium") == 0)
		strat = STRAT_MEDIUM;
	else if (ft_strcmp(s, "--complex") == 0)
		strat = STRAT_COMPLEX;
	else if (ft_strcmp(s, "--adaptive") == 0)
		strat = STRAT_ADAPTIVE;
	else
		return (0);
	opts->strategy = strat;
	return (1);
}
