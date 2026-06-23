/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:57:23 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/23 11:04:59 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// calculates approximate floor (previous integer) of the square root
int	ft_sqrt(int n)
{
	int	sqr;

	sqr = 0;
	while ((sqr * sqr) <= n)
		sqr++;
	return (sqr - 1);
}

// Runs through the stack and finds the current highest index
int	ft_highest_index(t_stack **b, int *count)
{
	t_stack_node	*traveller;

	traveller = (*b)->top;
	while (traveller->index != ((*b)->size - 1))
	{
		(*count)++;
		traveller = traveller->next;
	}
	return (traveller->index);
}
// give the correct index to each node
void	ft_sort_index(t_stack **stack)
{
	t_stack_node	*stack_comp;
	t_stack_node	*top;
	
	top = (*stack)->top;
	while (top != NULL)
	{
		top->index = 0;
		stack_comp = (*stack)->top;
		while (stack_comp != NULL)
		{
			if (top->nbr > stack_comp->nbr)
				top->index += 1;
			stack_comp = stack_comp->next;
		}
		top = top->next;
	}
}
// algorithm to sort 3 numbers
void ft_three_sort(t_stack *stack, t_info **info)
{
    if (stack->top->index > stack->top->next->index)
        ft_swap_a(stack, info);
    if (stack->top->next->index > stack->top->next->next->index)
        ft_reverse_a(stack, info);
    if (stack->top->index > stack->top->next->index)
        ft_swap_a(stack, info);
}
