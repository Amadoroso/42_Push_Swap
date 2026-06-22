/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:53:28 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/22 16:56:38 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
funcao para ordenar index do struct
funcao compara node atual com a linked list e sempre que encontrar um valor
menor que o do nbr do node, vai somar 1 ao index
 */
 /*Manda tudo para B com pb
Para cada elemento em B, calcula custo de inserção em A
Insere o mais barato
Repete até B estar vazio*/

void	ft_sort_index(t_stack **stack)
{
	t_stack_node	*stack_comp;
	t_stack_node	*top;

	top = (*stack)->top;
	while (top != NULL)
	{
		top->index = 0;
		stack_comp = (*stack)->top;
		while (stack_comp != NULL)
		{
			if (top->nbr > stack_comp->nbr)
				top->index += 1;
			stack_comp = stack_comp->next;
		}
		top = top->next;
	}
}
