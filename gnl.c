#include "get_next_line.h"
#include <stdio.h>

static	size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static	size_t	ft_end_of_line(char *store)
{
	size_t	i;

	i = 0;
	while (store[i])
	{
		if (store[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static	char	*ft_creat_line(char *store, char *line)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (store[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	while (i <= len)
	{
		line[i] = store[i];
		i++;
	}
	line[i] = '\0';
	store += i;
	return (line);
}

static	char	*ft_strcpy(char *store, char *buffer)
{
	size_t	i;

	i = 0;
	store = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!store)
		return (NULL);
	while (buffer[i])
	{
		store[i] = buffer[i];
		i++;
	}
	store[i] = '\0';
	return (store);
}

static	char	*ft_strcat(char *store, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_store;

	if (ft_strlen(store) < ft_strlen(buffer))
		return (ft_strcpy(store, buffer));
	new_store = malloc(sizeof(char) * (BUFFER_SIZE + ft_strlen(store) + 1));
	if (!new_store)
		return (NULL);
	while (store[i])
	{
		new_store[i] = store[i];
		i++;
	}
	free(store);
	while (buffer[j])
		new_store[i++] = buffer[j++];
	new_store[i] = '\0';
	return (new_store);
}

static	char	*ft_read_and_store(int fd, char *store, int already_read)
{
	char	buffer[BUFFER_SIZE + 1];

	already_read = read(fd, buffer, BUFFER_SIZE);
	buffer[already_read] = '\0';
	return (ft_strcat(store, buffer));
}

char	*get_next_line(int fd)
{
	static	char	*store;
	char			*line;
	int		already_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	already_read = 1;
	line = NULL;
	store = NULL;
	return (ft_read_and_store(fd, store, already_read));
}

int	main()
{
	int fd = open("./text.txt", O_RDONLY);

	char	*str = get_next_line(fd);
	printf("%s", str);
	close(fd);
	return (0);
}
