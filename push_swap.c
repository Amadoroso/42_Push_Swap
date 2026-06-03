/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:32:52 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/03 18:05:56 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_head;
	
	stack_head = ft_argv_parser(argc, argv);
	if (!stack_head)
		return (ft_putstr_fd("Error\n", 2), 1);
	
	int count;
	count = 0;
	while (stack_head)
	{
		printf("node %i index> %i\n", count, stack_head->index);
		printf("node %i int> %i\n", count, stack_head->nbr);
		printf("\n");
		stack_head = stack_head->next;
		count++;		
	}
	return (0);
}
