/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:37:35 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/05 18:56:42 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Frees the the full matrix that comes from ft_split
void	ft_split_free(char **matrix)
{
	int i;

	i = 0;
	while (*(matrix + i))
	{
		free(*(matrix + i));
		i++;
	}
	free(matrix);
}

// Parsing through argv
t_stack	*ft_argv_parser(int argc, char **argv)
{
	t_stack			*stack_head;
	int				size;
	int				i;
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
			i = 0;
			while (*(split_args + i))
			{
				if(!ft_stack_creator(*(split_args + i), &stack_head, size))
					return (ft_split_free(split_args), NULL);
				i++;
				size++;
			}
			ft_split_free(split_args);
		}
		argv++;
	}
	stack_head->size = size;
	return (stack_head);
}



