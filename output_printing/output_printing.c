/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_printing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:29:12 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/23 16:47:02 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// fills up info with the necessary info for printing. also prints if bench = 0
void	ft_info_filler(t_stack **stack_a, t_info **info, char *op)
{
	(void) stack_a;
	(*info)->total_ops++;
	ft_printf(1, "%s\n", op);
	if (!ft_strcmp(op, "sa"))
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
		(*info)->rb++;
	else if (!ft_strcmp(op, "rr"))
		(*info)->rr++;
	else if (!ft_strcmp(op, "rra"))
		(*info)->rra++;
	else if (!ft_strcmp(op, "rrb"))
		(*info)->rrb++;
	else if (!ft_strcmp(op, "rrr"))
		(*info)->rrr++;
}

// Prints output with more detail (stack_a->bench = 1)
void	ft_bench_printer(t_info **info, t_stack **stack_a)
{
	if (!stack_a || !*stack_a)
		return ;
	ft_printf(2, "[bench] disorder: %i.", (*info)->nbr);
	if ((*info)->dec < 10)
		ft_printf(2, "0%i%%\n", (*info)->dec);
	else
		ft_printf(2, "%i%%\n", (*info)->dec);
	ft_printf(2, "[bench] strategy: %s\n", (*stack_a)->flag);
	ft_printf(2, "[bench] total_ops: %i\n", (*info)->total_ops);
	ft_printf(2, "[bench] sa: %i sb: %i ", (*info)->sa, (*info)->sb);
	ft_printf(2, "ss: %i pa: %i ", (*info)->ss, (*info)->pa);
	ft_printf(2, "pb: %i\n", (*info)->pb);
	ft_printf(2, "[bench] ra: %i rb: %i ", (*info)->ra, (*info)->rb);
	ft_printf(2, "rr: %i rra: %i ", (*info)->rr, (*info)->rra);
	ft_printf(2, "rrb: %i rrr: %i\n", (*info)->rrb, (*info)->rrr);
}
