/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf16.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:34:12 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/27 12:50:12 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf16(unsigned long long n, char *base)
{
	char	c;
	int		count;

	count = 0;
	while (n >= 16)
	{
		count += ft_printf16(n / 16, base);
		n %= 16;
	}
	if (n < 16)
	{
		c = base[n];
		write(1, &c, 1);
		count++;
	}
	return (count);
}

// int main(void)
// {
// 	ft_printf16(-1, "0123456789abcdef");
// 	printf("%x", -1);
// 	return(0);
// }
