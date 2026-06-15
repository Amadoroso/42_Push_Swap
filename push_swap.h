/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:36:02 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/15 18:39:52 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// struct that holds the int, aswell as other info
typedef struct s_stack_node
{
	int					index;
	int					nbr;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;
	// it points to the node that is currently at the top of the stack but acording to the pdf, the first element is the top of the stack
	int				size; // variable to count how many nodes has the stack
	int				bench;
	char			*flag;
}					t_stack;

typedef struct s_stacks // struct that stores the value of stack a and b
{
	t_stack	a;
	t_stack	b;
}	t_stacks;

// struct to store info for printing
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
}		t_info;

// Managing stack nodes functions
void			ft_stack_clear(t_stack **stack_head);
t_stack_node	*ft_node_new(int index, int atoi_result);
void			ft_stack_add(t_stack **stack_head, t_stack_node *new_node);
t_stack			**ft_stack_creator(char *arg, t_stack **stack_head, int index);

// Parsing argv parsing
t_stack			*ft_argv_parser(char **argv);
t_stack			**ft_arg_processing(char *arg, t_stack **stack_head, int *size);

// Flag parsing
int				ft_flag_parser(t_stack **stack_head, char **argv);
char			*ft_flag_detector(char *arg);

// Parsing argv utils functions
int				ft_repetition_check(int atoi_result, t_stack **stack_head);
char			**ft_sanitize_and_split(char *arg);
void			ft_split_free(char **matrix);
int				ft_sanitize_wspaces(char *arg);
int				ft_iswspace(int c);

// index sorting
void			ft_sort_index(t_stack **stack);

// Disorder calculator, strategy selector and preparation for printing
t_info			*ft_disorder(t_stack **stack_head);
float			ft_disorder_calc(t_stack **stack_head);
char			*ft_disorder_strat(float disorder, t_stack **stack_head);

// algorithm routing + algorithms
void			ft_algorithm_routing(t_stack **stack_head, t_info **info);

void			ft_medium_algorithm(t_stack	**stack_head, t_info **info);

// Output printing
void			ft_bench_printer(t_info **info, t_stack **stack_head);
void			ft_info_filler(t_stack **stack_head, t_info **info, char *op);

//operations
void			ft_push_a(t_stack *a, t_stack *b);
void			ft_push_b(t_stack *a, t_stack *b);
void			ft_reverse(t_stack *stack);
void			ft_reverse_a(t_stack *stack);
void			ft_reverse_b(t_stack *stack);
void			ft_reverse_both(t_stacks *stacks);
void			ft_rotate(t_stack *stack);
void			ft_rotate_a(t_stack *stack);
void			ft_rotate_b(t_stack *stack);
void			ft_rotate_both(t_stacks *stacks);
void			ft_swap(t_stack *values);
void			ft_swap_a(t_stack *values);
void			ft_swap_b(t_stack *values);
void			ft_swap_both(t_stacks *stacks);


#endif