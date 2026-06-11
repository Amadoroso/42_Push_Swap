/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:47:08 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/05 17:14:21 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty. */

void ft_push_a(t_stack *a, t_stack *b)
{
	t_stack_node *node;
	
	if (b->top == NULL || b == NULL)
		return ;
	node = b->top; // the adress of node become the same as b->top
	b->top = b->top->next;  // our b->top becomes the next node of the list e.g if the stack b is 7, 8, 9
	if (b->top != NULL) // if is there any value on top
		b->top->prev = NULL; // clean the prev value
	node->next = a->top; // next points to the same adress as top
	if (a->top != NULL) // if is there any value on top of a
		a->top->prev = node; // the prev of the old top is the new top
	a->top = node; // then the prev value become node (the new top)
	node->prev = NULL; // prev of the new top is null
}
void ft_push_b(t_stack *a, t_stack *b) 
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
}