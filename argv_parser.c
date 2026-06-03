/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:37:35 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/03 10:30:33 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	argv++;
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


