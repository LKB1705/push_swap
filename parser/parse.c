/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedal <lfedal@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 21:24:43 by lfedal            #+#    #+#             */
/*   Updated: 2026/11/05 11:20:21 by lfedal           ###   ########.fr       */
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
	long nbr;
	int	i;
	int neg;
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
return(0);
}


int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*node;
	int		value;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			ft_printf("[%s] invalide (format)\n", argv[i]);
			free_stack(&a);
			return (1);
		}
		if (!str_to_int(argv[i], &value))
		{
			ft_printf("[%s] invalide (depassement)\n", argv[i]);
			free_stack(&a);
			return (1);
		}
		if (is_double(a, value))
		{
			ft_printf("[%s] invalide (doublon)\n", argv[i]);
			free_stack(&a);
			return (1);
		}
		node = ft_lstnew(value, i, &a);
		if (!node)
			return (1);
		ft_lstadd_back(&a, node);
		i++;
	}
	ft_printf("pile a :");
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