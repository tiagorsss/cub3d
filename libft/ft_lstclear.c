/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:25:53 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/12 11:53:46 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;
	t_list	*tmp;

	l = *lst;
	while (l)
	{
		tmp = l->next;
		ft_lstdelone(l, del);
		l = tmp;
	}
	*lst = NULL;
}
/*
void	ft_delete_int(void *data)
{
	free(data);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*new;
	t_list	*current;

    node1 = ft_lstnew("1");
    node2 = ft_lstnew("2");
    node3 = ft_lstnew("3");
	node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
	current = node1;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstclear(&node1, ft_delete_int);
	current = node1;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}*/