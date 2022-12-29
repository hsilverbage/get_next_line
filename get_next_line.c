/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:17:06 by hsilverb          #+#    #+#             */
/*   Updated: 2022/12/29 19:26:06 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

/*
	Read() return value is a size_t of many bytes it succeded to read, therefore if it was reached the end of the file, the return value
	and the buffer size will be 0. And it return (-1) in case of an error
	Create a stash to store the buffer until it reachs the end of the line
	Static variable keeps its value between 2 calls on the same fucntion

*/

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

char	*ft_trim_line(char *str)
{
	char	*new_line;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (str[len] != '\n')
		len++;
	new_line = malloc(sizeof(char) * (len + 2));
	if (!new_line)
		return (NULL);
	while (i < len)
	{
		new_line[i] = str[i];
		i++;
	}
	new_line[i] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_trim_newline(char *str)
{
	char	*next_line;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (str[i] != '\n')
		i++;
	next_line = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!next_line)
		return (0);
	i++;
	while(str[i])
		next_line[j++] = str[i++];
	str[i] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	static	char	*line;
	char			*buffer;
	int				ret;
	char			*temp;

	line = NULL;
	temp = NULL;
	ret = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_end_of_line(temp) == 0 || ret != 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		line = temp;
		temp = ft_strjoin(line, buffer);
		free(line);
	}
	line = ft_trim_line(temp);
	temp = ft_trim_newline(temp);
	if (ret == 0)
		free(temp);
	return (line);
}

int	main()
{
	// int fd = open("./text.txt", O_RDONLY);

	// printf("%s", get_next_line(fd));
	// close(fd);
	char *str = "falut";
	char *str2 = "fa va fish de flute";

	printf("%s \n", ft_strjoin(str, str2));
	return (0);
}
