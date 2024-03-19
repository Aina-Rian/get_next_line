/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harandri <harandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:35:11 by harandri          #+#    #+#             */
/*   Updated: 2024/03/19 09:57:01 by harandri         ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_strchr(char *str, char c)
{
	while(*str)
	{
		if(*str == c)
			return (1);
		str++;
	}
	return(0);
}

char *ft_strjoin(char *dst, char *src)
{
	int t_size;
	char *result;
	int i;
	int j;
	
	t_size = ft_strlen(dst) + ft_strlen(src);
	result = (char *)malloc(t_size + 1);
	if (!result)
		return (NULL);
	i = 0;
	while(dst[i] != '\0')
	{
		result[i] = dst[i];
		i++;
	}
	j = 0;
	while(src[j] != '\0')
	{
		result[i] = src[j];
		i++;
		j++;
	}
	result[t_size] = '\0';
	return (result);
}


