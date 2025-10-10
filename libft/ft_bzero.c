/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:19:47 by lumiguel          #+#    #+#             */
/*   Updated: 2023/10/19 15:13:19 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

/*
int	main(void)
{
	char	str[10];

    str[10] = "1daa312w";
    ft_bzero(str, 4);
    printf("minha:%s", str);
    bzero(str, 4);
    printf("original:%s", str);
    return (0);
}
*/
