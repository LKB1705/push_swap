/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oracio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:20:04 by oracio            #+#    #+#             */
/*   Updated: 2026/11/09 12:48:11 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_stack_a(int argc, char **argv)
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
}

// void	choose_methode(t_node *stack_a)
// {
// 	double	disorder;

// 	if (argv == "--simple")
// 		//methode simple O(n2)
// 	else if (argv == "--medium")
// 		//methode medium O(n1/2n)
// 	else if (argv == "--complex")
// 		//methode high O(n log n)
// 	else if (argv == "--adaptive")
// 		disorer = comp_disorder(stack_a);
// 		if (disorder < 0.2)
// 			//methode simple O(n2)
// 		else if (disorder >= 0.2 && disorder < 0.5)
// 			//methode medium O(n1/2n)
// 		else if (disorder >= 0.5)
// 			//methode high O(n log n)
// }

/*A voir pour ajouter la creation de la stack_b*/
