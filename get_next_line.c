/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:17:06 by hsilverb          #+#    #+#             */
/*   Updated: 2023/01/04 22:10:59 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	size_t	k = 0;
	while (s2[k])
		k++;
	printf("%zu len of s2", k);
	printf("%zu \n", ft_strlen(s2));
	if (!s1)
		str = ft_calloc((ft_strlen(s2) + 1), sizeof(char));
	else
		str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
		str[i++] = s2[j++];
	// str[i] = '\0';
	return (str);
}

char	*ft_trim_line(char *temp)
{
	char	*new_line;
	size_t		len;
	size_t		i;

	len = 0;
	i = 0;
	while (temp[len] && temp[len] != '\n')
		len++;
	new_line = ft_calloc((len + 1), sizeof(char));
	if (!new_line)
		return (NULL);
	while (i < len && temp[i])
	{
		new_line[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		new_line[i++] = '\n';
	// if (temp[i] == '\0')
	// 	new_line[i] = '\0';
	return (new_line);
}

char	*ft_trim_next_line(char *temp, char *line)
{
	char	*next_line;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (temp[i] == line[i] && temp[i] && line[i])
		i++;
	next_line = ft_calloc((ft_strlen(temp) - i + 1), sizeof(char));
	if (!next_line)
		return (NULL);
	while (temp[i])
		next_line[j++] = temp[i++];
	// next_line[j] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp;
	char		buffer[BUFFER_SIZE + 1];
	int			ret;

	line = NULL;
	if (!temp)
		temp = NULL;
	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ret != 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		temp = ft_strjoin(temp, buffer);
		if (ft_end_of_line(temp) == 1)
			break ;
	}
	line = ft_trim_line(temp);
	temp = ft_trim_next_line(temp, line);
	if (line[0] == '\0')
		return (free(line), free(temp), NULL);
	return (line);
}
