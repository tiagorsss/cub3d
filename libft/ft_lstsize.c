/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:03:47 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/09 17:11:25 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main(void) 
{
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    int content1 = 1;
    int content2 = 2;
    int content3 = 3;
    
    node1->content = &content1;
    node1->next = node2;
    node2->content = &content2;
    node2->next = node3;
    node3->content = &content3;
    node3->next = NULL;
    int size = ft_lstsize(node1);
    printf("%d\n", size);
    free(node1);
    free(node2);
    free(node3);
    return (0);
}
*/