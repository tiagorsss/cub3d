/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:26:18 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/12 12:03:23 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
}
/*
void	ft_delete_string(void *data)
{
	free(data);
}
int	main(void)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->content = ft_strdup("QuackQuack!");
	node->next = NULL;
	printf("OG: %s\n", (char *)node->content);
	ft_lstdelone(node, ft_delete_string);
	printf("Final: %s", (char *)node->content);
	return (0);
}
*/