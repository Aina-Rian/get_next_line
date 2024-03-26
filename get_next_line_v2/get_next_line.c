/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harandri <harandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:19:11 by harandri          #+#    #+#             */
/*   Updated: 2024/03/26 10:25:25 by harandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int buffer_size(int fd, char *line)
// {
	
// }

char	*get_next_line(int fd)
{
	char buff;
	char buffer[7000000];
	size_t bytes;
	int i;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	bytes = read(fd, &buff, 1);
	while(bytes > 0)
	{
		buffer[i++] = buff;
		if(buff == '\n')
			break;
		bytes = read(fd, &buff, 1);
	}
	buffer[i] = '\0';
	if(bytes <= 0 || i == 0)
		return(NULL);
	return (ft_strdup(buffer));
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	int i = 0;
	
	char *line;
	while (i < 15)
	{
		line = get_next_line(fd);
		printf("line %d => %s\n", i, line);
		free(line);
		i++;
	}
	return (0);
}

