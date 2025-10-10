/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:01:58 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/30 15:45:09 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_agrs(const char *str, unsigned long long i, va_list ptr)
{
	if (str[i + 1] == '%')
		return (ft_putchar(str[i + 1]));
	if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	else if (str[i + 1] == 's')
		return (ft_putstr(va_arg(ptr, char *)));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		return (ft_printnbr(va_arg(ptr, int)));
	else if (str[i + 1] == 'u')
		return (ft_putnbr_u(va_arg(ptr, unsigned int)));
	else if (str[i + 1] == 'X')
		return (ft_printf16(va_arg(ptr, unsigned int), UPPERBASE));
	else if (str[i + 1] == 'x')
		return (ft_printf16(va_arg(ptr, unsigned int), LOWERBASE));
	else if (str[i + 1] == 'p')
	{
		i = va_arg(ptr, unsigned long long);
		if (i != 0)
			return (ft_putstr("0x") + ft_printf16(i, LOWERBASE));
		else
			return (ft_putstr("(nil)"));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		count;

	count = 0;
	va_start(ptr, str);
	i = 0;
	if (str == (void *)0)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			count += ft_printf_agrs(str, i, ptr);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ptr);
	return (count);
}
/*
int	main(void)
{
	int n = ft_printf(NULL);
	ft_printf("%d", n);
	return (0);
}
*/
