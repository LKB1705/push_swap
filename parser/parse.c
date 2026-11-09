/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedal <lfedal@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 21:24:43 by lfedal            #+#    #+#             */
/*   Updated: 2026/11/09 11:36:33 by lfedal           ###   ########.fr       */
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

int	str_to_int(char *s, int *out)
{	
	long	nbr;
	int		i;
	int		neg;

	nbr = 0;
	neg = 1;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = nbr * 10 + (s[i] - '0');

		if ((nbr * neg) > INT_MAX || (nbr * neg) < 	INT_MIN )
			return(0);
		i++;
	}
	
	*out = (nbr * neg);
	return(1);
}


int	is_double(t_node *a, int value)
{
	if (a == NULL)
	{
		return(0);
	}

	while (a != NULL)
	{
		if (a->value == value)
			return(1);
		a = a->next;
	}
	return (0);
}

void	error_exit(t_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit (1);
}


t_node *build_stack(int argc, char **argv, t_opts *opts)
{
		t_node	*a;
	t_node	*node;
	int		value;
	int		i;

	a = NULL;
	i = 1;
	while (argc > i)
	{	
		if (is_flag(argv[i]))
		{
			if (parse_flag(argv[i], opts) == 0)
				error_exit(&a);
			i++;
			continue;
		}
		
		if (!is_valid_number(argv[i]))
			error_exit(&a);
		if (!str_to_int(argv[i], &value))
			error_exit(&a);
		if (is_double(a, value))
			error_exit(&a);

		node = ft_lstnew(value, i, &a);
		if (!node)
			error_exit(&a);
		ft_lstadd_back(&a, node);
		i++;
	}
	if (opts->strategy == STRAT_NONE)
		opts->strategy = STRAT_ADAPTIVE;
	return (a);
}




int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*node;
	t_opts	opts;

	opts.strategy = STRAT_NONE;
	opts.bench = 0;
	a = build_stack(argc, argv, &opts);
	ft_printf("strat=%d bench=%d | pile a :", opts.strategy, opts.bench);
	node = a;
	while (node)
	{
		ft_printf(" %d", node->value);
		node = node->next;
	}
	ft_printf("\n");
	free_stack(&a);
	return (0);
}