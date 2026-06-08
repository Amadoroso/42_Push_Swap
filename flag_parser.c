/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:17:01 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/08 12:02:56 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Detects which flag is in the arguments
char	*ft_flag_detector(char *arg)
{
	if (!ft_strcmp(arg, "--simple"))
		return ("--simple / O(n2)");
	if (!ft_strcmp(arg, "--medium"))
		return ("--medium / O(n√n)");
	if (!ft_strcmp(arg, "--complex"))
		return ("--complex / O(nlogn)");
	if (!ft_strcmp(arg, "--adaptive"))
		return ("--adaptive");
	return (NULL);
}

// Looks for flags in the arguments
int	ft_flag_parser(t_stack **stack_head, char **argv)
{
	int	i;
	int	flag;
	int	bench;

	i = 0;
	bench = 0;
	flag = 0;
	while (argv[i] && i < 2)
	{
		if (ft_flag_detector(argv[i]) && flag == 0)
		{
			(*stack_head)->flag = ft_flag_detector(argv[i]) + 2;
			flag++;
		}
		if (!ft_strcmp(argv[i], "--bench") && bench == 0)
		{
			(*stack_head)->bench = 1;
			bench++;
		}
		i++;
	}
	if (flag == 0)
		(*stack_head)->flag = "adaptive";
	return (bench + flag);
}
