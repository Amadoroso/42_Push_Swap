/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:45:51 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/04 16:46:52 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* sa (swap a): Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time. */


#include "push_swap.h"

static void	ft_swap(t_stack *values)
{
	t_stack_node	*first;
	t_stack_node	*second;
	
	if (values->size < 2)
		return ;
	first = values->top; // first = adress of values->top
	second = first->next;
	first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	values->top = second;
}
void	ft_swap_a (t_stack *values) // the swap a and b are equal because we must choose which stack are we working on
{
	ft_swap(values);
}

void	ft_swap_b (t_stack *values)
{
	ft_swap(values);
}

void	ft_swap_both(t_stacks *stacks)
{
	ft_swap(&stacks->a);
	ft_swap(&stacks->b);
}