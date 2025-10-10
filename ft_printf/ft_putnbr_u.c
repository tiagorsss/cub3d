/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:41:29 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/27 18:08:42 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	int		r;
	int		count;

	count = 0;
	if (n >= 10)
	{
		r = n % 10 + 48;
		count += ft_putnbr_u(n / 10);
		write(1, &r, 1);
		count++;
	}
	if (n < 10)
	{
		n += 48;
		write(1, &n, 1);
		count++;
	}
	return (count);
}
