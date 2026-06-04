/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:36:02 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/04 13:27:18 by jtravanc         ###   ########.fr       */
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
	t_int_node	*top; 
	// it points to the node that is currently at the top of the stack but acording to the pdf, the first element is the top of the stack
	int			size; // variable to count how many nodes has the stack
}   t_stack;

typedef struct s_stacks // struct that stores the value of stack a and b
{
	t_stack a;
	t_stack b;
}	t_stacks;


#endif