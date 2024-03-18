/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harandri <harandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:35:16 by harandri          #+#    #+#             */
/*   Updated: 2024/03/18 16:20:53 by harandri         ###   ########.fr       */
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
char	*get_next_line(int fd);
int	ft_strlen(char *str);
int ft_strchr(char *str, char c);
char *ft_strjoin(char *dst, char *buffer);
char *copy_and_free(char *res, char *buffer);
void	*ft_calloc(size_t nmemb, size_t size);

#endif