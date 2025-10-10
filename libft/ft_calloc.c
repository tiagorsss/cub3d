/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:38:05 by lumiguel          #+#    #+#             */
/*   Updated: 2023/10/12 21:29:05 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}
/*
int	main(void) {
    int *arr;
    int num = 3;

    arr = (int*)ft_calloc(num, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation falhada.\n");
        return (1);
    }
    int i = 0;
    while (i < num) 
    {
        if (arr[i] != 0) 
        {
            printf("Memory initialization falhada.\n");
            return (1);
        }
        i++;
    }
    free(arr);
    printf("Successful.\n");
    return (0);
}
*/
