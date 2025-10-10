/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:53:18 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/02 15:47:34 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(long j)
{
	long	temp;
	int		i;

	i = 0;
	temp = j;
	if (j == 0)
		return (1);
	while (temp > 0)
	{
		temp /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		negative;
	char	*numero;
	long	j;

	negative = 0;
	j = n;
	if (j <= -1)
	{
		negative = 1;
		j *= -1;
	}
	numero = (char *)malloc((ft_count(j) + negative + 1) * sizeof(char));
	if (numero == NULL)
		return (NULL);
	if (negative)
		numero[0] = '-';
	i = ft_count(j);
	numero[i + negative] = '\0';
	while (i > 0)
	{
		numero[i-- - 1 + negative] = '0' + j % 10;
		j /= 10;
	}
	return (numero);
}
/*
int main (void)
{
	int	i;

    i = 32;
    char *numero =ft_itoa(i);
    printf ("%s",numero);
    return(0);
}
*/
