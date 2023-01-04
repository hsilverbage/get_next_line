/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:18:11 by hsilverb          #+#    #+#             */
/*   Updated: 2023/01/04 21:55:01 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("./test1.txt", O_RDONLY);
	str = get_next_line(fd);
	// while (str)
	// {
	printf("%s", str);
	// 	str = get_next_line(fd);
	// }
	close(fd);
	return (0);
}

