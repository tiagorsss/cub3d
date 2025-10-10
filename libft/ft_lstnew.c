/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:22:05 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/10 16:24:46 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lista;

	lista = (t_list *)malloc(sizeof(*lista));
	if (!lista)
		return (NULL);
	lista->content = content;
	lista->next = NULL;
	return (lista);
}

// int main (void)
// {
// 	int	*dados;

//     dados = (int *)malloc(sizeof(int));

//     *dados = 42;
//     t_list *node =ft_lstnew(dados);
//     printf("%d",*((int *)node->content));
//     free(dados);
//     free(node);
//     return (0);
// }
