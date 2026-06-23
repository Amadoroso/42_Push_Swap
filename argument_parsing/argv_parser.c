/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:37:35 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/23 15:58:49 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Processes the current argument being parsed in argv_parser
t_stack	**ft_arg_processing(char *arg, t_stack **stack_a, int *size)
{
	char	**split_args;
	int		i;

	split_args = ft_sanitize_and_split(arg);
	if (!split_args)
	{
		if (!ft_stack_creator(arg, stack_a, *size))
			return (NULL);
		(*size)++;
	}
	else
	{
		i = 0;
		while (*(split_args + i))
		{
			if (!ft_stack_creator(*(split_args + i), stack_a, *size))
				return (ft_split_free(split_args), NULL);
			i++;
			(*size)++;
		}
		ft_split_free(split_args);
	}
	return (stack_a);
}

// Parsing through argv
t_stack	*ft_argv_parser(char **argv)
{
	t_stack			*stack_a;
	int				size;
	int				flags;

	stack_a = ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	argv++;
	flags = ft_flag_parser(&stack_a, argv);
	while (flags--)
		argv++;
	size = 0;
	while (*argv != 0)
	{
		if (!ft_arg_processing(*argv, &stack_a, &size))
			return (NULL);
		argv++;
	}
	stack_a->size = size;
	return (stack_a);
}
