/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:05:13 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/22 18:20:46 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack X by one
void	ft_rotate(t_stack *stack)
{
	t_stack_node	*top_node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	if (stack->top == NULL)
		return ;
	top_node = stack->top;
	last_node = ft_last_node(stack);
	if (top_node == last_node)
		return ;
	stack->top = top_node->next;
	stack->top->prev = NULL;
	last_node->next = top_node;
	top_node->prev = last_node;
	top_node->next = NULL;
}

// rotates a and prints/counts
void	ft_rotate_a(t_stack *a, t_info **info)
{
	ft_rotate(a);
	ft_info_filler(&a, info, "ra");
}

// rotates b and prints/counts
void	ft_rotate_b(t_stack *a, t_stack *b, t_info **info)
{
	ft_rotate(b);
	ft_info_filler(&a, info, "rb");
}

// rotates a and b and prints/counts
void	ft_rotate_both(t_stacks *stacks, t_info **info)
{
	t_stack	*stack_a;

	stack_a = &stacks->a;
	ft_rotate(&stacks->a);
	ft_rotate(&stacks->b);
	ft_info_filler(&stack_a, info, "rr");
}
