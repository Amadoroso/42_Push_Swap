/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:37:35 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/02 19:14:12 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error_checker(int argc, char **argv)
{
	int	*atoi_check;
	int	atoi_result;
	
	if (argc <= 1)
		return (1);
	while (*argv != 0)
	{
		atoi_result = ft_atoi(*argv, atoi_check);
		if (*atoi_check)
			ft_stack_a_creator();
		argv++;
	}
	return (0);
}
t_int_node *ft_stack_a_creator(int atoi_result)
{
	
}
