/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:32:52 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/05 20:27:37 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_head;
	
	stack_head = ft_argv_parser(argc, argv);
	if (!stack_head)
		return (ft_putstr_fd("Error\n", 2), 1);
/* 	
		
	t_stack_node	*traveller;
	int count;
	count = 0;
	traveller = stack_head->top;
	while (traveller)
		{
			printf("node %i index> %i\n", count, traveller->index);
			printf("node %i int> %i\n", count, traveller->nbr);
			printf("\n");
			traveller = traveller->next;
			count++;		
		}
	printf("t_stack size: %i\n", stack_head->size);
	
	 */
	ft_stack_clear(&stack_head);
	return (0);
}
