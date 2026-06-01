/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:08:50 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/06 13:49:58 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*static void	ft_modify(void *content)
{
	while (*((char *) content) != 0)
	{
		*((char *) content) = '1';
		content++;
	}
} */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
int	main()
{
	t_list	*ptr_node1;
	t_list	*ptr_node2;
	t_list	*start;
	char	*content;

	content = "ola adeus";
	ptr_node1 = ft_lstnew(ft_strdup(content));
	ptr_node2 = ft_lstnew(ft_strdup(content));
	start = ptr_node1;
	ft_lstadd_back(&start, ptr_node2);
	ft_lstiter(start, ft_modify);
	printf("%s\n", (char *) ptr_node1->content);
	return (0);
} */