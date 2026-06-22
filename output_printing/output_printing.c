/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_printing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:29:12 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/22 17:47:51 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// fills up info with the necessary info for printing. also prints if bench = 0
void	ft_info_filler(t_stack **stack_head, t_info **info, char *op)
{
	if (!(*stack_head)->bench)
		ft_printf("%s\n", op);
	else if (!ft_strcmp(op, "sa"))
		(*info)->sa++;
	else if (!ft_strcmp(op, "sb"))
		(*info)->sb++;
	else if (!ft_strcmp(op, "ss"))
		(*info)->ss++;
	else if (!ft_strcmp(op, "pa"))
		(*info)->pa++;
	else if (!ft_strcmp(op, "pb"))
		(*info)->pb++;
	else if (!ft_strcmp(op, "ra"))
		(*info)->ra++;
	else if (!ft_strcmp(op, "rb"))
		(*info)->rr++;
	else if (!ft_strcmp(op, "rr"))
		(*info)->rr++;
	else if (!ft_strcmp(op, "rra"))
		(*info)->rra++;
	else if (!ft_strcmp(op, "rrb"))
		(*info)->rrb++;
	else if (!ft_strcmp(op, "rrr"))
		(*info)->rrr++;
	(*info)->total_ops++;
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
