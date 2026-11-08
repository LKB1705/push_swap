/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:37:01 by oracio            #+#    #+#             */
/*   Updated: 2026/11/02 21:59:22 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "ft_printf.h"
# include "opps.h"
# include "algorithme.h"
# include "utils.h"

int	main(int argc, char **argv);
/* push_swap.c */
t_node	*create_stack_a(int argc, char **argv);

t_node	*value_to_rank(t_node *a);
t_node	*find_min(t_node *stack);

#endif
