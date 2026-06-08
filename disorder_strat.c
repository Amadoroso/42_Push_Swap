/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_strat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:45:56 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/08 15:32:01 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// adds the strategy complexity string to stack_head (needed for --bench)
char	*ft_disorder_strat(float disorder, t_stack **stack_head)
{
	if (disorder == 0 || !stack_head || !*stack_head
			|| !(*stack_head)->top || !(*stack_head)->top->next)
		return (NULL);
	if (!ft_strcmp((*stack_head)->flag, "Adaptive"))
	{
		if (disorder < 0.2)
			return ((*stack_head)->flag = "Adaptive / O(n2)");
		if (disorder >= 0.2 && disorder < 0.5)
			return ((*stack_head)->flag = "Adaptive / O(n√n)");
		if (disorder >= 0.5)
			return ((*stack_head)->flag = "Adaptive / O(nlogn)");	
	}
	return (NULL);
}

// Calculates the disorder of the passed (already confirmed to valid) args
float	ft_disorder_calc(t_stack **stack_head)
{
	t_stack_node	*node_ptr1;
	t_stack_node	*node_ptr2;
	int				mistakes;
	int				pairs;

	if (!stack_head || !stack_head || !(*stack_head)->top
		|| !(*stack_head)->top->next)
		return (0);
	mistakes = 0;
	pairs = 0;
	node_ptr1 = (*stack_head)->top;
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
	ft_disorder_strat((float) mistakes / pairs, stack_head);
	return ((float) mistakes / pairs);
}

// Adds the disorder value, prepared for printing to info
t_info	*ft_disorder(t_stack **stack_head)
{
	t_info	*info;
	float	disorder;
	
	disorder = ft_disorder_calc(stack_head);
	info = ft_calloc(1, sizeof(t_info));
	if (!info)
		return (NULL);
	info->disorder = disorder;
	info->nbr = disorder * 100;
	info->dec = (int) (disorder * 10000) % 100;
	return (info);
}
