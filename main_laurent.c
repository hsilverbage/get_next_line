# include "get_next_line.h"
# include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	/* one file - empty */
	// int fd = open("./empty.txt", O_RDONLY);
	// printf("%s", get_next_line(fd));
	// close(fd);
	// return (0);

	/* one file - one line one char */
	// int fd = open("./1char.txt", O_RDONLY);
	// printf("\n\n%s", get_next_line(fd));
	// close(fd);
	// return (0);

	/* one file - one line */
	// int fd = open("./test1.txt", O_RDONLY);
	// printf("\n%s", get_next_line(fd));
	// close(fd);
	// return (0);

	/* one file - two line */
	// int fd = open("./test2.txt", O_RDONLY);
	// printf("\n%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// close(fd);
	// return (0);

	/* one file - two line and BUFFER_SIZE >= len de line1 */
	// int fd = open("./test2.txt", O_RDONLY);
	// printf("\ngnl1=%s\n", get_next_line(fd));
	// printf("\ngnl2=%s", get_next_line(fd));
	// close(fd);
	// return (0);

	/* one file - one line one char */
	// int fd = open("./multiple_nl.txt", O_RDONLY);
	// printf("gnl=%s", get_next_line(fd));
	// printf("gnl=%s", get_next_line(fd));
	// printf("gnl=%s", get_next_line(fd));
	// printf("gnl=%s", get_next_line(fd));
	// close(fd);
	// return (0);

	/* one file - one line one char */
	// int fd = open("./variable_nls.txt", O_RDONLY);
	// printf("gnl=%s", get_next_line(fd));
	// printf("gnl=%s", get_next_line(fd));
	// printf("gnl=%s", get_next_line(fd));
	// printf("gnl=%s", get_next_line(fd));
	// printf("gnl=%s", get_next_line(fd));
	// close(fd);
	// return (0);

	// int fd = open("./read_error.txt", O_RDONLY);
	// printf("gnl=%s", get_next_line(fd));
	// printf("gnl=%s", get_next_line(fd));
	// fd = open("./read_error.txt", O_RDONLY);
	// printf("gnl=%s", get_next_line(fd));
	// fd = open("./read_error.txt", O_RDONLY);
	// printf("gnl=%s", get_next_line(fd));
	// close(fd);
	// return (0);

	/* one file - two line */
	// int fd = open("./41_with_nl.txt", O_RDONLY);
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// close(fd);
	// return (0);

	/* two files - multilines */
	// int fd1 = open("./test2.txt", O_RDONLY);
	// int fd2 = open("./test3.txt", O_RDONLY);
	// printf("\n%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("\n%s", get_next_line(fd2));
	// printf("%s", get_next_line(fd2));
	// close(fd1);
	// close(fd2);
	// return (0);

	/*int fd = open("text", O_RDONLY);
	char *str;
	str = get_next_line(0);
	while (str)
	{
	printf("%s", str);
	free(str);
	str = get_next_line(0);
	}*/

	int fd = open("./text.txt", O_RDONLY);

	char	*str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
