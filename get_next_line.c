/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:17:06 by hsilverb          #+#    #+#             */
/*   Updated: 2023/01/08 15:45:34 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		str = malloc(sizeof(char) * (ft_strlen(s2) + 1));
	else
		str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	if(s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

static char	*ft_trim_line(char *line)
{
	char	*new_line;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (line[len] != '\n' && line[len])
		len++;
	if (line[len] == '\n')
		new_line = malloc(sizeof(char) * (len + 2));
	else
		new_line = malloc(sizeof(char) * (len + 1));
	if (!new_line)
		return (free(line), NULL);
	while (i < len)
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

static char	*ft_trim_next_line(char *line, char *temp)
{
	size_t			i;
	size_t			j;
	unsigned int	len;

	j = 0;
	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[++i] != '\0')
	{
		len = i;
		while (line[len])
			len++;
		len -= i;
		while(j < len)
			temp[j++] = line[i++];
		temp[j] = '\0';
	}
	else
		temp = NULL;
	return (temp);
}

char	*get_next_line(int fd)
{
	static	char	temp[BUFFER_SIZE + 1];
	char			buffer[BUFFER_SIZE + 1];
	char			*line;
	int				ret;

	line = NULL;
	if (temp[0])
		line = temp;
	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	while (ret != 0 && ft_end_of_line(line) == 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	ft_trim_next_line(line, temp);
	line = ft_trim_line(line);
	if (ret == 0)
	{
		if (line)
			free(line);
		line = NULL;
	}
	return (line);
}
