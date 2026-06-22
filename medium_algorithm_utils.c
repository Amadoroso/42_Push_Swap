/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:57:23 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/22 15:50:53 by apinho-a         ###   ########.fr       */
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

// Combining "ft_push_a" and "ft_info_filler"
void	ft_pa_info(t_stack **a, t_stack **b, t_info **info)
{
	ft_push_a(*a, *b);
	ft_info_filler(a, info, "pa");
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

// Combining "ft_rotate_b" or "ft_reverse_b" with ft_info_filler.
// Simple char* is used to know if rotate or reverse
void	ft_rb_info(t_stack **a, t_stack **b, t_info **info, char *op)
{
	if (!ft_strcmp("rrb", op))
	{
		ft_reverse(*b);
		ft_info_filler(a, info, "rrb");
	}
	else if (!ft_strcmp("rb", op))
	{
		ft_rotate(*b);
		ft_info_filler(a, info, "rb");
	}
}
