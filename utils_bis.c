/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   utils_bis.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: obohbot <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/02 11:38:25 by obohbot        #+#    #+#                */
/*   Updated: 2026/11/02 11:38:49 by obohbot        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
