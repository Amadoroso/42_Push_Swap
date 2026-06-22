/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:57:23 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/22 16:16:22 by apinho-a         ###   ########.fr       */
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

