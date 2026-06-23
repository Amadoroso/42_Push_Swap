/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:32:52 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/23 11:23:48 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack     *stack_a;
    t_stacks    stacks;
    t_info      *info;

    if (argc <= 1)
        return (0);
    stack_a = ft_argv_parser(argv);
    if (!stack_a)
        return (ft_putstr_fd("Error\n", 2), 1);
    ft_sort_index(&stack_a);
    info = ft_disorder(&stack_a);
    if (!info)
        return (ft_putstr_fd("Error\n", 2), 1);
    stacks.a = *stack_a;
    stacks.b.top = NULL;
	stacks.b.size = 0;
    ft_algorithm_routing(&stack_a, &info, &stacks);
    if (stack_a->bench)
        ft_bench_printer(&info, &stack_a);
    free(info);
    ft_stack_clear(&stack_a);
    return (0);
}

// debugging function
/* void	ft_debug_print(t_stack *stack_a, t_info *info)
{
	t_stack_node	*traveller;
	int count;
	count = 0;
	traveller = stack_a->top;
	while (traveller)
	{
		printf("node %i index> %i\n", count, traveller->index);
		printf("node %i int> %i\n", count, traveller->nbr);
		printf("\n");
		traveller = traveller->next;
		count++;		
	}
	printf("t_stack size: %i\n", stack_a->size);
	printf("t_stack top: %p\n", stack_a->top);
	printf("t_stack top index (0 is correct): %d\n", stack_a->top->index);
	printf("t_stack bench?: %i\n", stack_a->bench);
	printf("t_stack flag: %s\n", stack_a->flag);
	printf("calculated disorder: %f\n", info->disorder);
} */