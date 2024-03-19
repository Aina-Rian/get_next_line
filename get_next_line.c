/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harandri <harandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:34:35 by harandri          #+#    #+#             */
/*   Updated: 2024/03/19 13:58:37 by harandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_all_buffer(int fd, char *buffer)
{
	size_t bytes;
	char *buff;
	
	if (!buffer)
		buffer = malloc(1);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff)
	{
		while (1)
		{
			bytes = read(fd, buff, BUFFER_SIZE);
			if(bytes <= 0)
			{
				free(buff);
				return (NULL);
			}
			buff[bytes] = '\0';
			buffer = copy_and_free(buffer, buff);
			if (ft_strchr(buff, '\n') == 1)
				break;
		}
		free(buff);
		printf("%zu", bytes);
		return (buffer);
	}
	return (NULL);
}

char *get_next(char *buffer)
{
	char *result;
	int i;
	int j;

	i = 0;
	j = 0;
	if (buffer[i] == '\n')
		i = 1;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	result = malloc(sizeof(char *) * i + 1);
	i += 1;
	j = 0;
	while(buffer[i])
	{
		result[j] = buffer[i];
		j++;
		i++;
	}
	free(buffer);
	return (result);
}

char *get_line(char *buffer)
{
	char *result;
	int i;
	int j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n')
		i++;
	result = malloc(sizeof(char *) * i + 1);
	while (buffer[j] != '\n')
	{
		result[j] = buffer[j];
		j++;
	}
	result[j] = '\0';
	return (result);
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
	result = get_line(buffer);
	buffer = get_next(buffer);
	return (result);
}
