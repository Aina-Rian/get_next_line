/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harandri <harandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:19:11 by harandri          #+#    #+#             */
/*   Updated: 2024/03/19 17:13:58 by harandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *line;
	char *buffer;
	int bytes;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (buffer)
	{
		while (1)
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes < 0)
			{
				free(buffer);
				return (NULL);
			}
			
			// ft_stsrchr
			
		}
		return (line);
	}
	return (NULL);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	int i = 0;
	
	while (i < 1)
	{
		printf("line %d => %s\n", i, get_next_line(fd));
		i++;
	}
	return (0); 
}