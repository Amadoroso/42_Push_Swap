/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 14:22:25 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/06 14:50:12 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_reverse(t_stack *stack)
{
	t_stack_node *top_node;
	t_stack_node *last_node;
	t_stack_node *new_last;
	if (stack == NULL || stack->top == NULL || stack ->top->next == NULL)
		return;
	top_node = stack->top;
	last_node = ft_lstlast(stack->top);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = top_node;
	top_node->prev = last_node;
	stack->top = last_node;
}

int main (void)
{
	
	return (0);
}
