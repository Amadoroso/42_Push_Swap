/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:36:02 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/02 19:55:08 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// struct that holds the int, aswell as other info
typedef struct s_int_node
{
	int		index;
	int		value;
	struct s_int_node	*next;
	struct s_int_node	*prev;
}			t_int_node;

typedef struct s_stack
{
	t_int_node	*top; // it points to the node that is currently at the top of the stack
	int			size; // variable to count how many nodes has the stack
}   t_stack;

typedef struct s_data // struct that points to stack a and b
{
	s_stack *a;
	s_stack *b;

}	t_data ;
/* s_int_node *stack_a
stack_a = &node */

#endif