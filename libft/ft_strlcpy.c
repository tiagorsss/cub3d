/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:20:38 by lumiguel          #+#    #+#             */
/*   Updated: 2023/10/12 21:22:46 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = (ft_strlen(src));
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	i = 0;
	return (len);
}
/*
int	main(void) 
{
    char dest[0];
    const char *src = "Hello, Wodwadawdawdarfsedwadawfsefsefsld!";
    size_t size = sizeof(dest);

    size_t copied = ft_strlcpy(dest, src, size);

    printf("Src size: %zu\n", copied);
    printf("Destination: %s\n", dest);

    return (0);
}
*/