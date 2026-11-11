/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedal <lfedal@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:13:14 by lfedal            #+#    #+#             */
/*   Updated: 2026/11/10 15:04:21 by lfedal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "algorithme.h"

 
int	*stack_to_array(t_node *a, int n)
{
int *vals;
int	i;

	vals = malloc(sizeof(int) * n);
	if (!vals)
		return (NULL);

	i = 0;

	while (i < n)
	{
		vals[i] = a->value;
		 a = a->next;
		i++;
	}
	return (vals);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	int		*vals;
	int		n;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i]), i, &a));
		i++;
	}
	n = stack_len(a);
	vals = stack_to_array(a, n);
	if (!vals)
	{
		free_stack(&a);
		return (1);
	}
	i = 0;
	while (i < n)
	{
		ft_printf("vals[%d] = %d\n", i, vals[i]);
		i++;
	}
	free(vals);
	free_stack(&a);
	return (0);
}