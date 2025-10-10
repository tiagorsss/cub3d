/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:16:29 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/13 15:45:49 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	i = 0;
	st1 = (unsigned char *)str1;
	st2 = (unsigned char *)str2;
	while (i < n)
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		++i;
	}
	return (0);
}
/*
int main () 
{
   char str1[15] =("abcdef");
   char str2[15] =("ABCDEF");
   int ret;

   ret = ft_memcmp(str1, str2, 5);

   if(ret > 0) {
      printf("str2 is less than str1");
   } else if(ret < 0) {
      printf("str1 is less than str2");
   } else {
      printf("str1 is equal to str2");
   }
   return(0);
}
*/