#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

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

// char	*ft_trim_line(char *str)
// {
// 	char	*new_line;
// 	size_t	len;
// 	size_t	i;

// 	i = 0;
// 	len = 0;
// 	while (str[len] != '\n')
// 		len++;
// 	new_line = malloc(sizeof(char) * (len + 2));
// 	if (!new_line)
// 		return (NULL);
// 	while (i < len)
// 	{
// 		new_line[i] = str[i];
// 		i++;
// 	}
// 	new_line[i] = '\n';
// 	new_line[i] = '\0';
// 	return (new_line);
// }

// char	*ft_trim_newline(char *str)
// {
// 	char	*next_line;
// 	size_t	i;
// 	size_t	j;

// 	j = 0;
// 	i = 0;
// 	while (str[i] != '\n')
// 		i++;
// 	next_line = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
// 	if (!next_line)
// 		return (0);
// 	i++;
// 	while(str[i])
// 		next_line[j++] = str[i++];
// 	str[i] = '\0';
// 	return (next_line);
// }

char	*get_next_line(int fd)
{
	// static	char	*line;
	char			buffer[BUFFER_SIZE + 1];
	int				ret;
	char			*temp;

	// line = NULL;
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
	// line = ft_trim_line(temp);
	// temp = ft_trim_newline(temp);
	return (temp);
}

int	main()
{
	int fd = open("./text.txt", O_RDONLY);

	char	*str = get_next_line(fd);
	printf("%s", str);

	char *str2 = get_next_line(fd);
	printf("2nd line ; %s \n", str2);

	char *str3 = get_next_line(fd);
	printf("3rd line ; %s \n", str3);
	close(fd);
	return (0);
}
