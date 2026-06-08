/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_strat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:45:56 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/08 12:21:15 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculates the disorder of the passed (already confirmed to valid) args
float	ft_disorder(t_stack *stack_head)
{
	t_stack_node	*node_ptr1;
	t_stack_node	*node_ptr2;
	int				mistakes;
	int				pairs;

	if (!stack_head || !stack_head->top || !stack_head->top->next)
		return (0);
	mistakes = 0;
	pairs = 0;
	node_ptr1 = stack_head->top;
	while (node_ptr1)
	{
		node_ptr2 = node_ptr1->next;
		while (node_ptr2)
		{
			if (node_ptr1->nbr > node_ptr2->nbr)
				mistakes++;
			pairs++;
			node_ptr2 = node_ptr2->next;
		}
		node_ptr1 = node_ptr1->next;
	}
	return ((float) mistakes / pairs);
}

// Determines the strategy to use depending on the disorder
char	*ft_disorder_strat(float disorder, t_stack **stack_head)
{
	if (disorder == 0 || !stack_head || !*stack_head
			|| !(*stack_head)->top || !(*stack_head)->top->next)
		return (NULL);
	if ((*stack_head)->flag && ft_strcmp((*stack_head)->flag,"--adaptive"))
		return (NULL);
	if (disorder < 0.2)
		return ((*stack_head)->flag = "--simple / O(n2)");
	if (disorder >= 0.2 && disorder < 0.5)
		return ((*stack_head)->flag = "--medium / O(n√n)");
	if (disorder >= 0.5)
		return ((*stack_head)->flag = "--complex / O(nlogn)");
	return (NULL);
}
