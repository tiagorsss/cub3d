/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:11:53 by lumiguel          #+#    #+#             */
/*   Updated: 2023/10/12 17:54:04 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int main () {
   const char src[50] = "Holla, como estas";
   char dest[50] = "ola";
   printf("Before memcpy dest = %s\n", dest);
   ft_memcpy(dest, src, 5);
   printf("After memcpy dest = %s\n", dest);
   return(0);
}
*/