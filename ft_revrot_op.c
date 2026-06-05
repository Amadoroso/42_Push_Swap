/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrot_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:05:58 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/05 18:03:21 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rra (reverse rotate a): Shift down all elements of stack a by one.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by one.
The last element becomes the first one.
rrr : rra and rrb at the same time. */

void ft_reverse(t_stack *stack)
{
	t_stack_node *top_node;
	t_stack_node *last_node;
	if (stack = NULL || stack->top == NULL)
		return;
	top_node = stack->top;
	last_node = ft_lstlast(stack->top);
	if (last_node = top_node)
		return;
	stack->top = top_node->next;
	stack->top->prev = NULL;
	
	
}

void ft_reverse_a (t_stack *stack)
{
	
}

void ft_reverse_b (t_stack *stack)
{
	
}

void ft_reverse_both (t_stack *stack)
{
	
}