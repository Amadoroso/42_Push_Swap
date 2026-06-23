/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:45:51 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/23 15:59:09 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Swap the first two elements at the top of stack X
void	ft_swap(t_stack *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	stack->top = second;
}

//Swaps a and prints/counts. Nothing if < 2 nodes.
void	ft_swap_a(t_stack *a, t_info **info)
{
	ft_swap(a);
	ft_info_filler(&a, info, "sa");
}

//Swaps b and prints/counts.. Nothing if < 2 nodes.
void	ft_swap_b(t_stack *a, t_stack *b, t_info **info)
{
	ft_swap(b);
	ft_info_filler(&a, info, "sb");
}

// Do swap for a and b at the same time.
void	ft_swap_both(t_stacks *stacks, t_info **info)
{
	t_stack	*stack_a;

	stack_a = &stacks->a;
	ft_swap(&stacks->a);
	ft_swap(&stacks->b);
	ft_info_filler(&stack_a, info, "ss");
}
