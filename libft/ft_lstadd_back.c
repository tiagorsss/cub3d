/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:22:20 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/10 16:04:05 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
/*
int main (void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*new;
	t_list	*current;

    node1 = ft_lstnew("1");
    node2 = ft_lstnew("2");
    node3 = ft_lstnew("3");
    new = ft_lstnew("4");
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    ft_lstadd_back(&node1,new);
    current = node1;
    while (current)
    {
        printf("%s",(char *)current->content);
        current = current->next;
    }
    free(node1);
    free(node2);
    free(node3);
    return (0);
}
*/