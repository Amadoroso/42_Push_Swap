/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_printing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:29:12 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/11 18:06:14 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Triggered in each algorithm
// Needs "if statment" inside each algorithm the algorithm
// Its only valid for stack_head->bench = 0
void	ft_normal_printer(char	*op)
{
	ft_printf("%s\n", op);
}

// Prints output with more detail (stack_head->bench = 1)
void	ft_bench_printer(t_info **info, t_stack **stack_head)
{
	if (!stack_head || !*stack_head)
		return ;
	ft_printf("[bench] disorder: %i.", (*info)->nbr);
	if ((*info)->dec < 10)
		ft_printf("0%i%%\n", (*info)->dec);
	else
		ft_printf("%i%%\n", (*info)->dec);
	ft_printf("[bench] strategy: %s\n", (*stack_head)->flag);
	ft_printf("[bench] total_ops: %i\n", (*info)->total_ops);
	ft_printf("[bench] sa: %i sb: %i ", (*info)->sa, (*info)->sb);
	ft_printf("ss: %i pa: %i ", (*info)->ss, (*info)->pa);
	ft_printf("pb: %i\n", (*info)->pb);
	ft_printf("[bench] ra: %i rb: %i ", (*info)->ra, (*info)->rb);
	ft_printf("rr: %i rra: %i ", (*info)->rr, (*info)->rra);
	ft_printf("rrb: %i rrr: %i\n", (*info)->rrb, (*info)->rrr);
}
