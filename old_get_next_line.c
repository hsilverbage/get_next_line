/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:17:06 by hsilverb          #+#    #+#             */
/*   Updated: 2023/01/04 17:06:36 by hsilverb         ###   ########lyon.fr   */
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
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

static	size_t	ft_end_of_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_trim_line(char *temp)
{
	char	*new_line;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (temp[len] != '\n' && temp[len])
		len++;
	if (temp[len] == '\n')
		new_line = malloc(sizeof(char) * (len + 2));
	else
		new_line = malloc(sizeof(char) * (len + 1));
	if (!new_line)
		return (NULL);
	while (i < len)
	{
		new_line[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_trim_newline(char *temp, int ret)
{
	char	*next_line;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (ret == 0)
		return (NULL);
	while (temp[i] != '\n' && temp[i])
		i++;
	next_line = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!next_line)
		return (NULL);
	i++;
	while (temp[i])
		next_line[j++] = temp[i++];
	temp[i] = '\0';
	free(temp);
	return (next_line);
}

{
	char			*line;
	char			buffer[BUFFER_SIZE + 1];
	int				ret;
	static	char	*temp;

	line = NULL;
	if (!temp)
		temp = "";
	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ret != 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		temp = ft_strjoin(temp, buffer);
		if (ft_end_of_line(temp) == 1)
			break;
	}
	line = ft_trim_line(temp);
	temp = ft_trim_newline(temp, ret);
	return (line);
}
