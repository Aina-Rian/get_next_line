/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harandri <harandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:34:35 by harandri          #+#    #+#             */
/*   Updated: 2024/03/15 17:04:21 by harandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int handle_buff(char *dst, char *src)
{
	int i;
	
	i = 0;
	while(*src)
	{
		i++;
		*dst = *src;
		src++;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static void	*ft_strcpy(char *dst, const char *src, size_t size)
{
	while (size > 0)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s_size;

	s_size = ft_strlen(src);
	if (size > s_size + 1)
	{
		ft_strcpy(dst, src, s_size);
		dst[s_size] = '\0';
	}
	else if (size != 0)
	{
		ft_strcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (s_size);
}

void hanldle_buffer(char *container, char *buffer)
{
	
}

char *get_next_line(int fd)
{
	char *result;
	size_t bytes;
	size_t i;
	char buff[BUFFER_SIZE + 1];

	i = 0;
	result = (char *)malloc(10000000);
	if(result == NULL)
		return(NULL);
	bytes = read(fd, &buff, BUFFER_SIZE);
	while (bytes)
	{
		result[i] = buff;
		i++;
		if(buff == '\n' || buff == EOF)
			break;
		bytes = read(fd, &buff, BUFFER_SIZE);
	}
	if (i == 0 || bytes < 0)
	{
		free(result);
		return (NULL);
	}
	return(result);
}