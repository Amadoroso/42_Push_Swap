/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_routing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:02:37 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/18 19:31:37 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// chooses the sorting algorithm used
void	ft_algorithm_routing(t_stack **stack_head, t_info **info)
{
/* 	if (!ft_strcmp((*stack_head)->flag, "Simple / O(n2)"))
		// simple */
	if (!ft_strcmp((*stack_head)->flag, "Medium / O(n√n)"))
		ft_medium_algorithm(stack_head, info);
/* 	if (!ft_strcmp((*stack_head)->flag, "Complex / O(nlogn)"))
		//complex
	if (!ft_strncmp((*stack_head)->flag, "Adaptive", 8))
	{
		if (!ft_strcmp((*stack_head)->flag + 10, "O(n2)"))
			// simple
		if (!ft_strcmp((*stack_head)->flag + 10, "O(n√n)"))
			ft_medium_algorithm(stack_head, info);
		if (!ft_strcmp((*stack_head)->flag + 10, "O(nlogn)"))
			//complex
	} */
}
