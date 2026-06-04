/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:44:37 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/04 18:41:10 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *nptr, int *atoi_check)
{
	long	result;
	int		neg;

	result = 0;
	neg = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	if (!ft_isdigit(*nptr))
		return (*atoi_check = -1, (int) result);
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
		if ((result * neg) > 2147483647 || (result * neg) < -2147483648)
			return (*atoi_check = -1, (int) result);
	}
	if (*nptr != 0)
		return (*atoi_check = -1, (int) result);
	return (*atoi_check = 1, (int)(result * neg));
}

/*
int	main()
{
	printf("%d\n", ft_atoi("	-1x234a"));
	printf("%d\n", atoi("	-1x234a"));
	return (0);
} */