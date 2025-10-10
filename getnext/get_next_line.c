/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:42:18 by lumiguel          #+#    #+#             */
/*   Updated: 2025/09/24 16:37:13 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd, int reset_flag)
{
	static char	buffer[(long)BUFFER_SIZE + 1];
	char		*line;
	long		quack;

	if (reset_flag) {
    for (int i = 0; i < BUFFER_SIZE; i++)
        buffer[i] = 0;
	}
	line = NULL;
	quack = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		while (quack < BUFFER_SIZE)
			buffer[quack++] = 0;
		return (NULL);
	}
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin2(line, buffer);
		unbuff(buffer);
		if (line[ft_strlen2(line) - 1] == '\n')
			return (line);
	}
	return (line);
}
/* 
 int	main(void)
{
	int fd;
	char *str;

	fd = open("string.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}    */
