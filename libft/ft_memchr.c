/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:15:07 by lumiguel          #+#    #+#             */
/*   Updated: 2023/10/17 16:05:41 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*qew;

	i = 0;
	qew = (unsigned char *)str;
	while (i < n)
	{
		if (qew[i] == (unsigned char)c)
			return ((void *)(qew + i));
		i++;
	}
	return (NULL);
}
/*
int main () 
{
   const char str[] = "abced.dwa";
   const char ch = '.';
   char *ret;

   ret = ft_memchr(str, ch, strlen(str));

   printf("String after |%c| is - |%s|\n", *ret, ret);

   return(0);
}
*/