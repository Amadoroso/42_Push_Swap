/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:53:28 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/10 18:24:31 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
funcao para ordenar index do struct
funcao compara node atual com a linked list e sempre que encontrar um valor
menor que o do nbr do node, vai somar 1 ao index
 */

void ft_sort_index(t_stack *stack)
{
		while (stack->top->next != NULL)
		{
			if (stack->top->nbr < stack->top->next->nbr)
				stack->top->index += 1;
			stack->top = stack->top->next;
		}
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
}