#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

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
	new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

int	main()
{
	char *str = "falution \\n fava ?";
	printf("%s \n", str);
	return (0);
}
