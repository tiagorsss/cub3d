/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:03:02 by lumiguel          #+#    #+#             */
/*   Updated: 2025/09/10 17:45:18 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
// // int main (void)
// // {
// // 	char str[] = "abcde";
// // 	ft_putstr_fd(str,1);
// // 	return (0);
// // }
// int main (void)
// {
// 	int fd = open("./text/test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
// 	char str[] = "0000000000000000000000000000000000000000";
// 	ft_putstr_fd(str,fd);
// 	return (0);
// }
