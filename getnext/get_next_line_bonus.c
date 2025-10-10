/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:42:18 by lumiguel          #+#    #+#             */
/*   Updated: 2024/01/02 13:16:23 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX][(long)BUFFER_SIZE + 1];
	char		*line;
	long		quack;

	line = NULL;
	quack = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
	{
		while (quack < BUFFER_SIZE)
			buffer[fd][quack++] = 0;
		return (NULL);
	}
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer[fd]);
		unbuff(buffer[fd]);
		if (line[ft_strlen(line) - 1] == '\n')
			return (line);
	}
	return (line);
}
/* 
int	main(void)
{
	int		fd;
	char	*str;
	int		fd1;
	char	*p;

	fd = open("test.txt", O_RDONLY);
	fd1 = open("test2.txt",  O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	str = get_next_line(fd);
	p = get_next_line(fd1);
	printf("%s\n", str);
	printf("%s\n", p);
		str = get_next_line(fd);
	p = get_next_line(fd1);
	printf("%s\n", str);
	printf("%s\n", p);
		str = get_next_line(fd);
	p = get_next_line(fd1);
	printf("%s\n", str);
	printf("%s\n", p);
	close(fd);
	return (0);
}
 */
