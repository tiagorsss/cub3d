/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:19:41 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/13 15:36:59 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// void printIndexEChar(unsigned int index, char *c)
// {
//     printf("Index: %u, Character: %c\n", index, *c);
// }
// int main (void)
// {
//     char str[] = "abcdefg1234,./";
//     ft_striteri(str, printIndexEChar);
//     return (0);
// }