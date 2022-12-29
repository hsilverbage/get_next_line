/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:18:50 by hsilverb          #+#    #+#             */
/*   Updated: 2022/12/29 15:11:19 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BUFFER_SIZE
#define		BUFFER_SIZE	6

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);

#endif
