/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:54:55 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/10 12:19:40 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
/*
int main (void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	int		content1;
	int		content2;
	int		content3;

    node1 = malloc(sizeof(t_list));
    node2 = malloc(sizeof(t_list));
    node3 = malloc(sizeof(t_list));
    content1 = 1;
    content2 = 2;
    content3 = 3;
    
    node1->content = &content1;
    node1->next = node2;
    node2->content = &content2;
    node2->next = node3;
    node3->content = &content3;
    node3->next = NULL;
    t_list * last = ft_lstlast(node1);
    printf("%d\n", *(int *)(last->content));
    free(node1);
    free(node2);
    free(node3);
    return (0);
}
*/