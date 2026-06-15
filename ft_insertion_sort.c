/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:53:28 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/15 15:50:13 by apinho-a         ###   ########.fr       */
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

/* void ft_three_sort(t_stack *stack)
{
	t_stack_node *top;
	t_stack_node *mid;
	t_stack_node *bot;
	
	top = stack->top;
	mid = top->next;
	bot = mid->next;

	if (top->index > mid->index)
		ft_swap_a(stack);
	if (mid->index > bot->index)
		ft_reverse_a(stack);
	if (top->index > mid->index)
		ft_swap_a(stack);
}

//original algorithm
void	ft_insertion_sort(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) 
		{
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
		i++;
	}
}

#include <stdio.h>

int main (void)
{
	int	i;
	int nmb[] = {23, 1, 356, 42, 3, 56, 43, 2, 3, 8, 7, 8, 9, 6, 32, 21, 45};
	ft_insertion_sort (nmb, 17);
	i = 0;
	while (i < 17)
	{
		printf("%d ", nmb[i]);
		i++;
	}
	return (0);
} */