/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harandri <harandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:19:11 by harandri          #+#    #+#             */
/*   Updated: 2024/03/20 14:32:33 by harandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void get_buffer(int fd, t_list **buffer)
{
	
}

char	*get_next_line(int fd)
{
	static t_list *buffer;
	char *line;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	
	

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