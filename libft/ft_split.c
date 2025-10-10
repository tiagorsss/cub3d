/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:40:17 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/25 08:22:25 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	i;

	if (!*s)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

void	*frees(char **lstout, int i)
{
	while (i >= 0)
		free(lstout[i--]);
	free(lstout);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)ft_calloc((ft_countword(s, c) + 1), sizeof(char *));
	if (!lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i] = ft_substr(s, 0, word_len);
			if (lst[i++] == NULL)
				return (frees(lst, i - 1));
			s += word_len;
		}
	}
	return (lst);
}

// int	main(void)
// {
// 	char	**array;
// 	int		i;

// 	char	str[20]= "0 2 4 1";
// 	array = ft_split(str, ' ');
// 	i = 0;
// 	while (array[i] != NULL)
// 	{
// 		printf("%s", array[i]);
// 		i++;
// 	}
// 	free(array);
// 	return (0);
// }
