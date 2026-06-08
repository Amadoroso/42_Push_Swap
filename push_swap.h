/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:36:02 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/08 12:07:53 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

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

// Disorder calculator and strategy selector
float			ft_disorder(t_stack *stack_head);
char			*ft_disorder_strat(float disorder, t_stack **stack_head);

// Output printing
void			ft_output_printer(float disorder, t_stack **stack_head);


#endif