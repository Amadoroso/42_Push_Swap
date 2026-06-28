/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:36:02 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/28 19:15:23 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack_node
{
	int					index;
	int					nbr;
	int					pos;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;
	int				size;
	int				bench;
	char			*flag;
}					t_stack;

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
}	t_stacks;

typedef struct s_info
{
	float	disorder;
	int		nbr;
	int		dec;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_info;

void			ft_stack_clear(t_stack **stack_head);
t_stack_node	*ft_node_new(int index, int atoi_result);
void			ft_stack_add(t_stack **stack_head, t_stack_node *new_node);
t_stack_node	*ft_last_node(t_stack *stack);
t_stack			**ft_stack_creator(char *arg, t_stack **stack_head, int index);

t_stack			*ft_argv_parser(char **argv);
t_stack			**ft_arg_processing(char *arg, t_stack **stack_a, int *size);

int				ft_flag_parser(t_stack **stack_a, char **argv);
char			*ft_flag_detector(char *arg);

int				ft_repetition_check(int atoi_result, t_stack **stack_a);
char			**ft_sanitize_and_split(char *arg);
void			ft_split_free(char **matrix);
int				ft_sanitize_wspaces(char *arg);
int				ft_iswspace(int c);

void			ft_sort_index(t_stack **stack);

t_info			*ft_disorder(t_stack **stack_a);
float			ft_disorder_calc(t_stack **stack_a);
char			*ft_disorder_strat(float disorder, t_stack **stack_a);

void			ft_algorithm_routing(t_stack **stack_a,
					t_info **info, t_stacks *stacks);

void			ft_chunk_sort(t_stack **a, t_stack **b, t_info **info);
void			ft_final_sort(t_stack **a, t_stack **b, t_info **info);
t_stack			**ft_medium_algorithm(t_stack **stack_a, t_info **info);

int				ft_sqrt(int n);
int				ft_highest_index(t_stack **b, int *count);
void			ft_three_sort(t_stack *stack, t_info **info);

void			ft_set_position(t_stack *stack);
void			ft_execute_move_simple(t_stacks *stacks, t_info **info,
					int target_pos);
void			ft_min_to_top(t_stacks *stacks, t_info **info);
void			ft_simple_insertion_sort(t_stack **stack_a, t_stacks *stacks,
					t_info **info);

void			ft_radix_sort(t_stack *stack_a, t_info **info);

void			ft_bench_printer(t_info **info, t_stack **stack_a);
void			ft_info_filler(t_stack **stack_a, t_info **info, char *op);

void			ft_push_a(t_stack *a, t_stack *b, t_info **info);
void			ft_push_b(t_stack *a, t_stack *b, t_info **info);

void			ft_reverse(t_stack *stack);
void			ft_reverse_a(t_stack *a, t_info **info);
void			ft_reverse_b(t_stack *a, t_stack *b, t_info **info);
void			ft_reverse_both(t_stacks *stacks, t_info **info);

void			ft_rotate(t_stack *stack);
void			ft_rotate_a(t_stack *a, t_info **info);
void			ft_rotate_b(t_stack *a, t_stack *b, t_info **info);
void			ft_rotate_both(t_stacks *stacks, t_info **info);

void			ft_swap(t_stack *stack);
void			ft_swap_a(t_stack *a, t_info **info);
void			ft_swap_b(t_stack *a, t_stack *b, t_info **info);
void			ft_swap_both(t_stacks *stacks, t_info **info);

#endif