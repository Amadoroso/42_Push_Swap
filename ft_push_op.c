/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:47:08 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/04 16:47:04 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty. */

void ft_push(t_stack *a, t_stack *b)
{
	t_stack_node *node;
	
	node = a->top;
	b->top->prev = node;
	node->next =  
}
void ft_push_a()
{}
void ft_push_b()
{}