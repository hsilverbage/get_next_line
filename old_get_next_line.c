/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:17:06 by hsilverb          #+#    #+#             */
/*   Updated: 2023/01/07 19:51:53 by hsilverb         ###   ########lyon.fr   */
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
		return (NULL);
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
		return (temp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			buffer[BUFFER_SIZE + 1];
	int				ret;
	static	char	temp[BUFFER_SIZE + 1];

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
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(line), NULL);
		if (ft_end_of_line(temp) == 1)
			break;
	}
	ft_trim_next_line(line, temp);
	line = ft_trim_line(line);
	return (line);
}
