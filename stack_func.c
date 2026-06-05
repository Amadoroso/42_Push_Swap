/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:30:05 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/05 18:38:22 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Frees memory for a given list (stack) of nodes (stack_node)
void	ft_stack_clear(t_stack **stack_head)
{
	t_stack_node	*next;
	t_stack_node	*traveller;

	if (!stack_head || !*stack_head)
		return ;
	traveller = (*stack_head)->top;
	while (traveller)
	{
		next = traveller->next;
		free(traveller);
		traveller = next;
	}
	free(*stack_head);
}

// adds a new node (stack_node) to the right of the list (stack)
void	ft_stack_add(t_stack **stack_head, t_stack_node *new_node)
{
	t_stack_node	*traveller;

	if (!(*stack_head)->top)
	{
		(*stack_head)->top = new_node;
		return ;
	}
	traveller = (*stack_head)->top;	
	while (traveller->next != NULL)
		traveller = traveller->next;
	traveller->next = new_node;
	new_node->prev = traveller;
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

// Creates the stack from the arguments. If error -> Frees(all) + returns(NULL)
t_stack	**ft_stack_creator(char *arg, t_stack **stack_head, int index)
{
	int				atoi_check;
	int				atoi_result;
	t_stack_node	*new_node;
	
	atoi_result = ft_atoi(arg, &atoi_check);
	if (atoi_check == -1 || ft_repetition_check(atoi_result, stack_head) > 0)
		return(ft_stack_clear(stack_head), NULL);
	else
	{
		new_node = ft_node_new(index, atoi_result);
		if (!new_node)
			return (ft_stack_clear(stack_head), NULL);
		ft_stack_add(stack_head, new_node);	
	}
	return (stack_head);
}
