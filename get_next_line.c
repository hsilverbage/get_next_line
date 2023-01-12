#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
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
	if(!str)
	{
		if(s1)
			free(s1);
		return (NULL);
	}
	if (s1)
	{
		while(s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	while(s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

char	*ft_trim_buf(char *line, char *buf)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if(!line)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		return (buf);
	}
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n' && line[i + 1] != '\0')
	{
		i++;
		while (line[i])
			buf[j++] = line[i++];
		buf[j] = '\0';
	}
	else
		ft_bzero(buf, BUFFER_SIZE + 1);
	return (buf);
}

char	*ft_trim_line(char *line)
{
	char	*new_line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!line)
		return (line);
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		new_line = malloc(sizeof(char) * (i + 2));
	else
		new_line = malloc(sizeof(char) * (i + 1));
	if(!new_line)
	{
		if (line)
			free(line);
		return (NULL);
	}
	while(j < i)
	{
		new_line[j] = line[j];
		j++;
	}
	if(line[j] == '\n')
		new_line[j++] = '\n';
	new_line[j] = '\0';
	if (line)
		free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static	char	buf[BUFFER_SIZE + 1];
	char			*line;
	int				ret;

	line = NULL;
	if (buf[0])
		line = ft_strjoin(line, buf);
	if(read(fd, NULL, 0) == -1)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(line), NULL);
	ret = 1;
	while (ret != 0 && ft_end_of_line(line) != 1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (ret != 0)
			line = ft_strjoin(line, buf);
	}
	ft_trim_buf(line, buf);
	line = ft_trim_line(line);
	return (line);
}
