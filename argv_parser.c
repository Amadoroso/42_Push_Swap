/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:37:35 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/04 18:41:53 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks for repetitions
int	ft_repetition_check(int atoi_result, t_stack **stack_head)
{
	int				rep;
	t_stack_node	*traveller;

	if (!stack_head)
		return (1);
	traveller = (*stack_head)->top;
	rep = 0;
	while (traveller)
	{
		if(atoi_result == traveller->nbr)
			rep++;
		traveller = traveller->next;
	}
	return (rep);
}

// Creates the stack from the arguments. If error -> Frees(all) + returns(-1)
t_stack	**ft_stack_creator(char **argv, t_stack **stack_head)
{
	int				atoi_check;
	int				atoi_result;
	int				i;
	t_stack_node	*new_node;
	
	i = 0;
	while (*(argv + i) != 0)
	{
		atoi_result = ft_atoi(*(argv + i), &atoi_check);
		if (atoi_check == -1 || ft_repetition_check(atoi_result, stack_head) > 0)
			return(ft_stack_clear(stack_head), NULL);
		else
		{
			new_node = ft_node_new(i, atoi_result);
			if (!new_node)
				return (ft_stack_clear(stack_head), NULL);
			ft_stack_add(stack_head, new_node);	
		}
		i++;
	}
	(*stack_head)->size = i;
	return (stack_head);
}

// Parsing through argv arguments
t_stack	*ft_argv_parser(int argc, char **argv)
{
	t_stack	*stack_head;

	if (argc <= 1)
	return (NULL);
	stack_head = ft_calloc(1, sizeof(t_stack));
	argv++;
	if (!ft_stack_creator(argv, &stack_head))
		return (NULL);
	return (stack_head);
}


