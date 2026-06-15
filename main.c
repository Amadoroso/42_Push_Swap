/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:32:52 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/15 16:02:21 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int argc, char **argv)
{
	t_stack	*stack_head;
	t_info	*info;

	if (argc <= 1)
		return (0);
	stack_head = ft_argv_parser(argv);
	if (!stack_head)
		return (ft_putstr_fd("Error\n", 2), 1);
	ft_sort_index(&stack_head);
	info = ft_disorder(&stack_head);
	if (!info)
		return (ft_putstr_fd("Error\n", 2), 1);
	ft_algorithm_routing(&stack_head, &info);
	if (stack_head->bench)
		ft_bench_printer(&info, &stack_head);

/* 	t_stack_node	*traveller;
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
	printf("t_stack top: %p\n", stack_head->top);
	printf("t_stack top index (0 is correct): %d\n", stack_head->top->index);
	printf("t_stack bench?: %i\n", stack_head->bench);
	printf("t_stack flag: %s\n", stack_head->flag);
	printf("calculated disorder: %f\n", info->disorder); */
	free(info);
	ft_stack_clear(&stack_head);
	return (0);
}
