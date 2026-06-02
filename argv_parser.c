/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:37:35 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/02 20:32:05 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_stack_clear(t_int_node **stack_head)
{
	t_int_node	*next;

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

void ft_stack_creator(t_int_node **stack_head, int atoi_result)
{
	
}

int	ft_argv_parser(int argc, char **argv)
{
	int	*atoi_check;
	int	atoi_result;
	t_int_node *a_stack;
	
	if (argc <= 1)
		return (-1);
	a_stack = ft_calloc(ft_strlen(argv) + 1, sizeof(t_int_node));
	while (*argv != 0)
	{
		atoi_result = ft_atoi(*argv, atoi_check);
		if (*atoi_check == -1)
			return(ft_stack_clear(a_stack), -1);
		else
			ft_stack_creator(a_stack, atoi_result);
		argv++;
	}
	return (0);
}


