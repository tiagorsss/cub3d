/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:58:17 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/06 16:24:27 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	r;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n < 10)
	{
		n += 48;
		write(fd, &n, 1);
		return ;
	}
	if (n >= 10)
	{
		r = n % 10 + 48;
		ft_putnbr_fd(n / 10, fd);
		write(fd, &r, 1);
	}
}
