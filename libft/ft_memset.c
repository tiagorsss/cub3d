/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:43:31 by lumiguel          #+#    #+#             */
/*   Updated: 2023/10/12 17:54:09 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*qwe;

	i = 0;
	qwe = (unsigned char *)str;
	while (i < n)
	{
		qwe[i++] = (unsigned char)c;
	}
	return (str);
}
