/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:53:28 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/22 18:29:50 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pre-sorts stack node's index
// Percorre stack_a and compares each node. Everytime a nbr is bigger index++
void	ft_sort_index(t_stack **stack_a)
{
	t_stack_node	*stack_comp;
	t_stack_node	*top;

	top = (*stack_a)->top;
	while (top != NULL)
	{
		top->index = 0;
		stack_comp = (*stack_a)->top;
		while (stack_comp != NULL)
		{
			if (top->nbr > stack_comp->nbr)
				top->index += 1;
			stack_comp = stack_comp->next;
		}
		top = top->next;
	}
}
