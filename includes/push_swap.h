/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:37:01 by oracio            #+#    #+#             */
/*   Updated: 2026/11/09 12:47:35 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	bool			abv_med;
	bool			chpst;
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

int		main(int argc, char **argv);

/* push_swap.c */
t_node	*create_stack_a(int argc, char **argv);

/* utils.c */
int		ft_atoi(char *str);
t_node	*ft_lstnew(int content, int i, t_node **stack_a);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);

/* utils_1.c */
void	free_stack(t_node **stack);
void	set_index(t_node *stack);
int		stack_len(t_node *stack);
t_node	*ft_lstpop_front(t_node **lst);
t_node	*ft_lstpop_back(t_node **lst);

/* utils_2.c */
t_node	*find_min(t_node *stack);
t_node	*find_max(t_node *stack);
t_node	*find_target_b(t_node *src, t_node *b);
int		min_int(int a, int b);
void	sort_three(t_node **a);

/* utils_cost.c */
int		abs_int(int n);
int		max_int(int a, int b);
int		find_cost(t_node *node, int len);
void	set_cost(t_node *a, t_node *b);
t_node	*find_cheapest(t_node *a);

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

/*pop front et back*/
t_node	*ft_lstpop_front(t_node **lst);
t_node	*ft_lstpop_back(t_node **lst);

/*add front et back*/
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);

/* parser/parse.c */
int		is_valid_number(char *s);
int		str_to_int(char *s, int *out);
int		is_double(t_node *a, int value);
void	error_exit(t_node **a);
t_node	*build_stack(int argc, char **argv, t_opts *opts);

/* parser/parse_flag.c */
int		ft_strcmp(char *s1, char *s2);
int		is_flag(char *s);
int		parse_flag(char *s, t_opts *opts);

/* norm_rank.c */
t_node	*value_to_rank(t_node *a);

/* -- Algo simple -- */
void	extr_min(t_node **a, t_node **b);
void	bring_min_to_top(t_node **a);

/* -- Algo Turk -- */
void	turk(t_node **a, t_node **b);
void	make_move(t_node **a, t_node **b, t_node *cheapest);
void	call_rotation(t_node **a, t_node **b, int sign, int common);
void	signed_rotation(t_node **a, t_node **b, int a_cost, int b_cost);
void	rotate_stack(t_node **stack, int cost, char name);
void	back_to_a(t_node **a, t_node **b);
t_node	*find_target_a(t_node *src, t_node *a);

#endif
