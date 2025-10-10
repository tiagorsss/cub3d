/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:17:32 by lumiguel          #+#    #+#             */
/*   Updated: 2023/10/19 15:17:57 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			ptr = (char *)(s + i);
		i++;
	}
	if (s[i] == '\0' && (unsigned char)c == '\0')
		return ((char *)(s + i));
	return (ptr);
}
/*
int	main(void) {
  
    char str[20] = "dacivadawi";
    int i = 105;

    char *result = ft_strrchr(str, i);

    if (result != NULL)
        printf("Character '%c' found at position %d\n", (char)i, result - str);
    else
        printf("Character not found in the string\n");

    return (0);
}
*/