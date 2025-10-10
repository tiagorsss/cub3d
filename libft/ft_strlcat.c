/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:20:36 by lumiguel          #+#    #+#             */
/*   Updated: 2023/10/19 15:17:31 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	destlen;

	i = 0;
	destlen = (ft_strlen(dst));
	if (size < ft_strlen(dst))
		len = (ft_strlen(src) + size);
	if (size >= ft_strlen(dst))
		len = (ft_strlen(src) + ft_strlen(dst));
	if (size == 0)
		return (len);
	while (src[i] && destlen < size - 1)
		dst[destlen++] = src[i++];
	dst[destlen] = 0;
	i = 0;
	return (len);
}
/*
int	main(void) 
{
    char dest[0] = "";
    const char *src = "Hwd!";
    size_t size = sizeof(dest);

    size_t copied = ft_strlcat(dest, src, size);
    
    printf("Src size: %zu\n", copied);
    printf("Destination: %s\n", dest);

    return (0);
}
*/