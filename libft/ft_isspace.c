/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 23:18:33 by lumiguel          #+#    #+#             */
/*   Updated: 2025/09/19 23:18:42 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isspace(char c)
{
    return (c == ' '  ||  // space
            c == '\t' ||  // horizontal tab
            c == '\n' ||  // newline
            c == '\v' ||  // vertical tab
            c == '\f' ||  // form feed
            c == '\r');   // carriage return
}
