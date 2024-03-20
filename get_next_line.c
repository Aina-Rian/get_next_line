/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harandri <harandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:34:35 by harandri          #+#    #+#             */
/*   Updated: 2024/03/20 16:05:59 by harandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_all_buffer(int fd, char *buffer)
{
	size_t bytes = 1;
	char *buff;
	
	if (!buffer)
		buffer = malloc(1);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff)
	{
		while (bytes)
		{
			bytes = read(fd, buff, BUFFER_SIZE);
			if(bytes <= 0)
			{
				free(buff);
				return (NULL);
			}
			buff[bytes] = 0;
			buffer = copy_and_free(buffer, buff);
			if (ft_strchr(buff, '\n') == 1)
				break;
		}
		free(buff);
		return (buffer);
	}
	return (NULL);
}

char *get_next(char *buffer)
{
	char *result;
	int i;
	int j;
	int buff_size;
	
	i = 0;
	j = 0;
	buff_size = ft_strlen(buffer);
	if (buffer[i] == '\n')
		i = 1;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	result = malloc(sizeof(char *) * (buff_size - i) + 1);
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
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	result = malloc(sizeof(char *) * i + 2);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		result[i] = buffer[i];
		i++;
	}
	// if (buffer[j] &&  buffer[j] == '\n')
	// 	result[j + 1] = '\n';
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
	if (result[0] == '\0')
	{
		free(result);
		return (NULL);
	}
	return (result);
}
