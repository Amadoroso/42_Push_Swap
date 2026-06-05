/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:37:35 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/05 18:39:08 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Parsing through argv
t_stack	*ft_argv_parser(int argc, char **argv)
{
	t_stack			*stack_head;
	int				size;
	char			**split_args;
	
	if (argc <= 1)
		return (NULL);
	stack_head = ft_calloc(1, sizeof(t_stack));
	if (!stack_head)
		return (NULL);
	argv++;
	size = 0;
	while (*argv != 0)
	{
		split_args = ft_sanitize_and_split(argv);
		if (!split_args)
		{
			if (!ft_stack_creator(*argv, &stack_head, size))
				return (NULL);
			size++;
		}
		else
		{
			while (*split_args)
			{
				if(!ft_stack_creator(*split_args, &stack_head, size))
					return(NULL);
				split_args++;
				size++;
			}
		}
		argv++;
	}
	stack_head->size = size;
	return (stack_head);
}



