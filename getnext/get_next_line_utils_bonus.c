/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:28:24 by lumiguel          #+#    #+#             */
/*   Updated: 2024/01/02 13:13:00 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	long	quack;
	long	quack2;
	char	*str;

	quack = -1 + (!s1);
	quack2 = 0;
	if (!s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[++quack])
		str[quack] = s1[quack];
	while (s2[quack2] && s2[quack2] != '\n')
	{
		str[quack + quack2] = s2[quack2];
		quack2++;
	}
	if (s2[quack2] == '\n')
		str[quack + quack2] = s2[quack2];
	str[ft_strlen(s1) + ft_strlen(s2)] = 0;
	free(s1);
	return (str);
}

long	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (s && s[i] == '\n')
		i++;
	return (i);
}

void	unbuff(char *buff)
{
	long	quack;
	long	quack2;

	quack = 0;
	quack2 = 0;
	while (quack < BUFFER_SIZE && buff[quack] != '\n')
		buff[quack++] = 0;
	if (buff[quack] == '\n')
	{
		buff[quack++] = 0;
		while (buff[quack])
		{
			buff[quack2] = buff[quack];
			buff[quack] = 0;
			quack++;
			quack2++;
		}
	}
}
