/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:20:51 by lumiguel          #+#    #+#             */
/*   Updated: 2023/10/12 17:56:16 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c += 32);
	return (c);
}
/*
int main (void)
{
	int	c;

    c = ';';
    printf("%c",ft_tolower(c));
    return(0);
}
*/