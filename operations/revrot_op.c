/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:05:58 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/29 08:37:46 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse(t_stack *stack)
{
	t_stack_node	*top_node;
	t_stack_node	*last_node;

	if (stack == NULL || stack->top == NULL || stack ->top->next == NULL)
		return ;
	top_node = stack->top;
	last_node = ft_last_node(stack);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = top_node;
	top_node->prev = last_node;
	stack->top = last_node;
}

// reverse rotates a and prints/counts
void	ft_reverse_a(t_stack *a, t_info **info)
{
	ft_reverse(a);
	ft_info_filler(&a, info, "rra");
}

// reverse rotates b and prints/counts
void	ft_reverse_b(t_stack *a, t_stack *b, t_info **info)
{
	ft_reverse(b);
	ft_info_filler(&a, info, "rrb");
}

// reverse rotates a and b and prints/counts
void	ft_reverse_both(t_stacks *stacks, t_info **info)
{
	t_stack	*stack_a;

	stack_a = &stacks->a;
	ft_reverse(&stacks->a);
	ft_reverse(&stacks->b);
	ft_info_filler(&stack_a, info, "rrr");
}
