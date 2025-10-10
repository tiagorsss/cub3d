/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:14:15 by lumiguel          #+#    #+#             */
/*   Updated: 2024/05/07 15:01:40 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		str[i + j] = *s2;
		j++;
		s2++;
	}
	str[i + j] = '\0';
	return (str);
}
/*
int	main(void)
{
	char prefix[20]="abced";
	char suffix[20]="fghjkl";
	printf ("%s",ft_strjoin(prefix,suffix));
	return (0);
}
*/