/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_printing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:29:12 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/08 11:35:46 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Prints output with more detail (bench = 1)
void	ft_bench_printer(float	disorder, t_stack **stack_head)
{
	
}

// Prints output with more detail (bench = 1)
void	ft_op_printer()
{
	
}

// Output printing routing
void	ft_output_printer(float disorder, t_stack **stack_head)
{
	if (!stack_head || !*stack_head)
		return ;
	if (!(*stack_head)->bench)
		return (ft_op_printer());
	if ((*stack_head)->bench)
		return (ft_bench_printer(disorder, &stack_head));
}
