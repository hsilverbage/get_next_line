/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read_vid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:41:16 by hsilverb          #+#    #+#             */
/*   Updated: 2022/12/27 20:03:17 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define	BUFFER_SIZE	1024

int	main()
{
	int fd;
	int ret;
	char buffer[BUFFER_SIZE + 1];

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error");
		return (1);
	}
	ret = read(fd, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	printf("%s \n", buffer);
	printf("%d \n", ret);

	return (0);
}
