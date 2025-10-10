/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:04:40 by lumiguel          #+#    #+#             */
/*   Updated: 2024/05/06 18:08:45 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		len = 0;
	}
	else if (start + len >= ft_strlen(s))
		len = (ft_strlen(s) - start);
	str = (char *)malloc(len + 1);
	if (!s || !str)
	{
		return (NULL);
	}
	while (start < ft_strlen(s) && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
/*
int main (void)
{
	const char	str[20];
	int			comeco;

    str[20] = "abcdefghij";
    comeco = 3;
    
    printf("%s",ft_substr(str,comeco,3));
    return(0);
}
*/