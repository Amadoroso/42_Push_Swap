/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:37:35 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/02 21:12:12 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_stack_clear(t_stack_node **stack_head)
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
	free (stack_head);
	stack_head = NULL;
}

t_stack_node *ft_node_new(int index, int atoi_result)
{
	t_stack_node	*new_node;
	
	new_node = ft_calloc(1, sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->index = index;
	new_node->nbr = atoi_result;
	return (new_node);
}

void	ft_stack_add(t_stack_node *stack_head, t_stack_node *new_node)
{	
	while (stack_head->next != NULL)
		stack_head = stack_head->next;
	stack_head->next = new_node;
}

int	ft_argv_parser(int argc, char **argv)
{
	int				*atoi_check;
	int				atoi_result;
	int				index;
	t_stack_node	*stack_head;
	t_stack_node	*new_node;
	
	if (argc <= 1)
		return (-1);
	stack_head = ft_calloc(1, sizeof(t_stack_node));
	if (!stack_head)
		return (-1);
	index = 0;
	atoi_check = NULL;
	while (*argv != 0)
	{
		atoi_result = ft_atoi(*argv, atoi_check);
		if (*atoi_check == -1)
			return(ft_stack_clear(&stack_head), -1);
		else
		{
			new_node = ft_node_new(index, atoi_result);
			if (!new_node)
				return (ft_stack_clear(&stack_head), -1);
			ft_stack_add(stack_head, new_node);			
		}
		argv++;
		index++;
	}
	return (0);
}


