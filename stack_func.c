/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:30:05 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/03 16:59:08 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Frees memory for a given list (stack) of nodes (stack_node)
void	ft_stack_clear(t_stack_node **stack_head)
{
	t_stack_node	*next;

	if (!stack_head || !*stack_head)
		return ;
	while (*stack_head != NULL)
	{
		next = (*stack_head)->next;
		free(*stack_head);
		*stack_head = next;
	}
}

// adds a new node (stack_node) to the front of the list (stack)
void	ft_stack_add(t_stack_node **stack_head, t_stack_node *new_node)
{
	t_stack_node	*traveller;

	traveller = *stack_head;
	while (traveller->next != NULL)
		traveller = traveller->next;
	traveller->next = new_node;
}

// Callocs new node memory
t_stack_node	*ft_node_new(int index, int atoi_result)
{
	t_stack_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->index = index;
	new_node->nbr = atoi_result;
	return (new_node);
}
