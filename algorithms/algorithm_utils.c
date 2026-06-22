/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:57:23 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/22 21:58:51 by jtravanc         ###   ########.fr       */
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
void ft_three_sort(t_stack *stack)
{
	t_stack_node *top;
	t_stack_node *mid;
	t_stack_node *bot;
	
	top = stack->top;
	mid = top->next;
	bot = mid->next;

	if (top->index > mid->index)
		ft_swap_a(stack);
	if (mid->index > bot->index)
		ft_reverse_a(stack);
	if (top->index > mid->index)
		ft_swap_a(stack);
}
