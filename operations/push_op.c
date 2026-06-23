/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:47:08 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/23 15:58:58 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Take the first element at the top of b and put it at the top of a
void	ft_push_a(t_stack *a, t_stack *b, t_info **info)
{
	t_stack_node	*node;

	if (b->top == NULL || b == NULL)
		return ;
	node = b->top;
	b->top = b->top->next;
	if (b->top != NULL)
		b->top->prev = NULL;
	node->next = a->top;
	if (a->top != NULL)
		a->top->prev = node;
	a->top = node;
	node->prev = NULL;
	b->size--;
	a->size++;
	ft_info_filler(&a, info, "pa");
}

// Take the first element at the top of a and put it at the top of b
void	ft_push_b(t_stack *a, t_stack *b, t_info **info)
{
	t_stack_node	*node;

	if (a->top == NULL || a == NULL)
		return ;
	node = a->top;
	a->top = a->top->next;
	if (a->top != NULL)
		a->top->prev = NULL;
	node->next = b->top;
	if (b->top != NULL)
		b->top->prev = node;
	b->top = node;
	node->prev = NULL;
	a->size--;
	b->size++;
	ft_info_filler(&a, info, "pb");
}
