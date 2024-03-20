/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harandri <harandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:19:14 by harandri          #+#    #+#             */
/*   Updated: 2024/03/20 09:28:56 by harandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#ifndef  BUFFER_SIZE
# define  BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char *line;
	struct s_list *next;
}				t_list;


char	*get_next_line(int fd);

#endif