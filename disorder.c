/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:45:56 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/08 10:51:53 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_disorder(t_stack *stack_head)
{
	t_stack_node	*node_ptr1;
	t_stack_node	*node_ptr2;
	int				mistakes;
	int				pairs;

	if ((!stack_head || !stack_head->top || !stack_head->top->next))
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
