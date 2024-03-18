/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harandri <harandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:35:11 by harandri          #+#    #+#             */
/*   Updated: 2024/03/18 16:24:27 by harandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tptr;

	tptr = s;
	while (n > 0)
	{
		*tptr = c;
		tptr++;
		n--;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*cptr;

	cptr = malloc(nmemb * size);
	if (cptr == NULL)
		return (0);
	else
		ft_bzero(cptr, nmemb * size);
	return (cptr);
}

char *ft_strjoin(char *dst, char *buffer)
{
	int t_size;
	char *result;
	int i;
	int j;
	
	t_size = ft_strlen(dst) + ft_strlen(buffer);
	result = (char *)malloc(t_size + 1);
	i = 0;
	while(dst[i] != '\0')
	{
		result[i] = dst[i];
		i++;
	}
	j = 0;
	while(buffer[j] != '\0')
	{
		result[i] = buffer[j];
		i++;
		j++;
	}
	result[t_size] = '\0';
	return (result);
}


