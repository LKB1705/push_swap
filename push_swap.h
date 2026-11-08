/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedal <lfedal@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:37:01 by oracio            #+#    #+#             */
/*   Updated: 2026/11/08 16:35:07 by lfedal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	int				abv_med;
	int				chpst;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;


# define STRAT_NONE		0
# define STRAT_SIMPLE	1
# define STRAT_MEDIUM	2
# define STRAT_COMPLEX	3
# define STRAT_ADAPTIVE	4

typedef struct s_opts
{
	int	strategy;
	int	bench;
}	t_opts;

/* push_swap.c */
t_node	*create_stack_a(int argc, char **argv);

/* utils.c */
int		ft_atoi(char *str);
t_node	*ft_lstnew(int content, int i, t_node **stack_a);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);

/* utils_bis.c */
void	free_stack(t_node **stack);
t_node	*ft_lstpop_front(t_node **lst);
t_node	*ft_lstpop_back(t_node **lst);
void	set_index(t_node *stack);
int		stack_len(t_node *stack);

/* opp_s.c */
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

/* opp_p.c */
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);

/* opp_r.c */
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

/* opp_rr.c */
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
/* parser/parse.c */
int		is_valid_number(char *s);
int		str_to_int(char *s, int *out);
int		is_double(t_node *a, int value);
void	error_exit(t_node **a);
t_node	*build_stack(int argc, char **argv);
/* parser/parse_flag.c */
int		ft_strcmp(char *s1, char *s2);
int		is_flag(char *s);
int		parse_flag(char *s, t_opts *opts);

#endif
