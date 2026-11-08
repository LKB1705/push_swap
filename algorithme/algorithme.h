/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:08:03 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/06 15:12:32 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHME_H
# define ALGORITHME_H

# include "opps.h"
# include "utils.h"

/* -- Algo simple -- */
void	extr_min(t_node **a, t_node **b);
void	bring_min_to_top(t_node **a);

/* -- Algo Turk -- */
void	turk(t_node **a, t_node **b);

#endif
