/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrot_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:05:58 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/22 15:30:05 by apinho-a         ###   ########.fr       */
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
/* 	t_stack_node *new_last; */
	if (stack == NULL || stack->top == NULL || stack ->top->next == NULL)
		return;
	top_node = stack->top;
	last_node = ft_last_node(stack);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = top_node;
	top_node->prev = last_node;
	stack->top = last_node;
}

void ft_reverse_a (t_stack *stack)
{
	ft_reverse (stack);
}

void ft_reverse_b (t_stack *stack)
{
	ft_reverse (stack);
}

void ft_reverse_both (t_stacks *stacks)
{
	ft_reverse(&stacks->a);
	ft_reverse(&stacks->b);	
}