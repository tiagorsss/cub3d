/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:28:20 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/13 11:54:16 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	int	i;

	if (!str1 && !str2)
		return (NULL);
	if (str1 > str2)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(str1 + i) = *(char *)(str2 + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(str1 + i) = *(char *)(str2 + i);
			i++;
		}
	}
	return (str1);
}
/*
int main () 
{
   char dest[] = "oldstring";
   const char src[]  = "newstring";

   printf("Antes dest = %s, src = %s\n", dest, src);
   //memmove(dest, src, 9);
   ft_memmove(dest, src, 9);
   printf("Depois dest = %s, src = %s\n", dest, src);

   return(0);
}
*/