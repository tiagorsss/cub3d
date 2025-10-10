/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:20:26 by lumiguel          #+#    #+#             */
/*   Updated: 2023/10/17 15:54:10 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}
/*
int	main(void) {
  
    char str[20] = "dacivadaw*i";
    int i = 42;

    char *result = ft_strchr(str, i);

    if (result != NULL)
        printf("Character '%c' found at position %ld\n", (char)i, result - str);
    else
        printf("Character not found in the string\n");

    return (0);
}
*/