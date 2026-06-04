/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:36:02 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/04 16:46:00 by apinho-a         ###   ########.fr       */
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

// Holds the size and top points to top node (index 0)
typedef struct	s_stack
{
	t_stack_node	*top;
	int				size;
}				t_stack;

// Managing stack nodes functions
void			ft_stack_clear(t_stack_node **stack_head);
t_stack_node	*ft_node_new(int index, int atoi_result);
void			ft_stack_add(t_stack_node **stack_head, t_stack_node *new_node);

// Parsing argv functions
int				ft_repetition_check(int atoi_result, t_stack_node **stack_head);
int				ft_stack_creator(char **argv, t_stack_node	**stack_head);
t_stack_node	*ft_argv_parser(int argc, char **argv);

#endif