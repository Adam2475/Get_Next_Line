/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adapassa <adapassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:58:24 by adapassa          #+#    #+#             */
/*   Updated: 2024/01/26 13:23:57 by adapassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_putstr(char *str)
{
    while (*str)
        write(1, &(*(str++)), 1);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!dest && !src)
		return (0);
	while (++i < n)
		((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}

static char	*ft_strdup(const char *s)
{
	char	*pt1;
	int		l;

    	if (!s)
        	return (NULL);
	l = ft_strlen((char *)s);
	pt1 = malloc(sizeof(char) * (l + 1));
	if (!pt1)
		return (0);
	ft_memcpy(pt1, s, l);
	pt1[l] = '\0';
	return (pt1);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s3 = (char *)calloc(sizeof(char), (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!s3)
		return (0);
    	if (s1)
    	{
        	while (s1[i] != '\0')
        	{
            		s3[i] = s1[i];
            		i++;
        	}
    	}
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

static char *ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
    	if (!s)
        	return (0);
	if (c == 0)
		return (str + ft_strlen((char *)s));
	while (s[i] != (unsigned char)c)
	{
		if (!str[i])
			break ;
		else
			i++;
	}
	if (str[i] != (unsigned char)c)
		return (NULL);
	return ((str + i));
}

char **trim_buffer(char *str)
{
    int i;
    char **tmp;

    i = 0;
    while (str[i] != '\0' && str != NULL)
    {
        if (str[i] == '\n')
        {
            tmp = ft_split(str, '\n');
            return (tmp);
        }
        i++;
    }
    return (NULL);
}

static char **buffer_handler(char *buffer, int fd)
{
    char    *tmp;
    char    **trim_result;
    char    **stock;
    int     read_bytes;

    tmp = (char *)calloc(sizeof(char), (BUFFER_SIZE + 1));
    if (!tmp)
        return (NULL);
    read_bytes = read(fd, tmp, BUFFER_SIZE);
    if (read_bytes == 0)
    {
        free(tmp);
        return (NULL);
    }
    trim_result = trim_buffer(tmp);
    if (trim_result != NULL)
        stock = (char **)calloc(sizeof(char *), 2);
    else
        stock = (char **)calloc(sizeof(char *), 1);
    if (!stock)
    {
        free(tmp);
        return (NULL);
    }
    if (trim_result)
    {
        tmp = trim_result[0];
        tmp = ft_strjoin(tmp, "\n");
        stock[1] = ft_strdup(trim_result[1]);
        free(trim_result[0]);
        free(trim_result[1]);
        free(trim_result);
    }
    if (buffer)
        tmp = ft_strjoin(buffer, tmp);
    stock[0] = ft_strdup(tmp);
    free(tmp);
    return (stock);
}

char    *get_next_line(int fd)
{
    char            *stock_buffer;
    static char     *res;
    char            *next_line;
    char            **holder;
    int             i;

    i = 0;
    next_line = NULL;
    stock_buffer = NULL;
    // Last control to fix the segfault with invalid fd
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, next_line, 0) < 0)
	    return (NULL);
    if (res)
	    stock_buffer = ft_strjoin(stock_buffer, res);
    while (ft_strchr(stock_buffer, '\n') == 0)
    {
        holder = buffer_handler(stock_buffer, fd);
        if (holder == NULL && stock_buffer == NULL)
        {
            free(stock_buffer);
            return (NULL);
        }
        else if (holder == NULL && stock_buffer[0] == '\0')
            return (NULL);
        else if (holder == NULL)
        {
            res = NULL;
            next_line = stock_buffer;
            //free(stock_buffer);
            return (next_line);
        }
        stock_buffer = ft_strdup(holder[0]);
        res = ft_strdup(holder[1]);
    }
    next_line = ft_strdup(stock_buffer);
	free(holder[0]);
	free(holder[1]);
    free(holder);
    free(stock_buffer);
    return (next_line);
}
