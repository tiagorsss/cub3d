/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:20:27 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/27 18:17:37 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int		i;
	int		count;

	count = 0;
	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
	{
		write(1, &s[i++], 1);
		count++;
	}
	return (count);
}
