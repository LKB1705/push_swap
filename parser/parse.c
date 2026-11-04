/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedal <lfedal@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 21:24:43 by lfedal            #+#    #+#             */
/*   Updated: 2026/11/05 00:00:34 by lfedal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

int	is_valid_number(char *s)
{
	int i;

	i = 0;

if (s[0] == '\0')
	return(0);

if (s[0] == '-' || s[0] =='+')
			{
				i++;
				if (s[i] > '9' || s[i] < '0')
					return(0);
			}

	while (s[i])
	{
		 if (s[i] > '9' || s[i] < '0')
			return(0);
			
	i++;
	}
	return(1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_valid_number(argv[i]))
			ft_printf("[%s] valide\n", argv[i]);
		else
			ft_printf("[%s] invalide\n", argv[i]);
		i++;
	}
	return (0);
}