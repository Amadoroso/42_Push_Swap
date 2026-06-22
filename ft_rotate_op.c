/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:05:13 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/22 15:50:18 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ra (rotate a): Shift up all elements of stack a by one.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by one.
The first element becomes the last one.
rr : ra and rb at the same time. */
void	ft_rotate(t_stack *stack)
{
	t_stack_node	*top_node;
	t_stack_node	*last_node;
	if (stack == NULL)
		return;
	if (stack->top == NULL)
		return ;
	top_node = stack->top; // aqui esta igual ao endereco do top do node
	last_node = ft_last_node(stack);
	if (top_node == last_node)
		return;
	stack->top = top_node->next;
	stack->top->prev = NULL;
	last_node->next = top_node;
	top_node->prev = last_node;
	top_node->next = NULL;
}

void ft_rotate_both (t_stacks *stacks)
{
	ft_rotate(&stacks->a);
	ft_rotate(&stacks->b);	
}
