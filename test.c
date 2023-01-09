#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i = 0;

	dest = malloc(sizeof(char) * 6);
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	printf("dest %s \n", dest);
	return(dest);
}

int main()
{
	char	*str = "falut";
	char	*src;
	char	*dest;
	int	i = 0;

	src = malloc(sizeof(char) * (6));
	while (str[i])
	{
		src[i] = str[i];
		i++;
	}
	src[i] = '\0';
	printf("src : %s \n", src);
	dest = ft_strcpy(dest, src);
	free(src);
	printf("dest %s \n", dest);
	return (0);
}
