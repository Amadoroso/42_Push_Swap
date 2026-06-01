/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:36:58 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/06 13:52:11 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

/*
int main ()
{
	t_list *lst;
	t_list *ptr_node1;
	t_list *ptr_node2;
	int lst_size;

	ptr_node1 = ft_lstnew("ola node 1");
	ptr_node2 = ft_lstnew("adeus node 2");

	lst = ptr_node1;
	ft_lstadd_front(&lst, ptr_node2);
	ft_lstadd_front(&lst, ptr_node1);
	lst_size = ft_lstsize(lst);

	printf("%d\n", lst_size);
} */