/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harandri <harandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:34:35 by harandri          #+#    #+#             */
/*   Updated: 2024/03/18 17:06:19 by harandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *copy_and_free(char *res, char *buffer)
{
	char *result;

	result = ft_strjoin(res, buffer);
	free(res);
	return (result);
}

char *get_all_buffer(int fd, char *res)
{
	size_t bytes;
	char *buffer;
	
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	// bytes = 1;
	bytes = read(fd, buffer, BUFFER_SIZE);	
	while (bytes > 0)
	{
		res = ft_strjoin(buffer, buffer);
		if (ft_strchr(buffer, '\n') == 1)
			break;
		bytes = read(fd, buffer, BUFFER_SIZE);	
	}
	return (res);
	// res = ft_strjoin(res, buffer);
}


char *get_next_line(int fd)
{
	static char *buffer;
	char *result;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = get_all_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	
	return (buffer);
}
