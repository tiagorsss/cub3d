/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:56:22 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/27 18:19:13 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(long int n)
{
	int	r;
	int	count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count = 1;
	}
	if (n >= 10)
	{
		r = n % 10 + 48;
		count += ft_printnbr(n / 10);
		write(1, &r, 1);
		count ++;
	}
	if (n < 10)
	{
		n += 48;
		write(1, &n, 1);
		count++;
	}
	return (count);
}
