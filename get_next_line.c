/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adapassa <adapassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:58:24 by adapassa          #+#    #+#             */
/*   Updated: 2024/02/01 14:41:45 by adapassa         ###   ########.fr       */
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
            tmp = ft_minisplit(str);
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

    //stock = NULL;
    //trim_result = NULL;
    tmp = (char *)calloc(sizeof(char), (BUFFER_SIZE + 1));
    if (!tmp)
        return (NULL);
    read_bytes = read(fd, tmp, BUFFER_SIZE);
    tmp[ft_strlen(tmp)] = '\0'; 
    if (read_bytes == 0)
    {
        free(tmp);
        return (NULL);
    }
    trim_result = trim_buffer(tmp);
    stock = (char **)calloc(sizeof(char *), 2);
    if (!stock)
    {
        return (NULL);
    }
    if (trim_result)
    {
        free(tmp);
        tmp = ft_strjoin(trim_result[0], "\n");
        stock[1] = ft_strdup(trim_result[1]);
        free(trim_result[1]);
        free(trim_result[0]);
        free(trim_result);
    }
    stock[0] = ft_strjoin(buffer, tmp);
    free(tmp);
    return (stock);
}


char    *get_next_line(int fd)
{
    char            *stock_buffer;
    static char     *res;
    char            *next_line;
    char            **holder;

    next_line = NULL;
    stock_buffer = NULL;
    holder = NULL;
    // Last control to fix the segfault with invalid fd
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, next_line, 0) < 0)
	    return (NULL);
    if (res)
    {
        if (ft_strchr(res, '\n') != 0)
        {
            holder = ft_minisplit(res);
            free(res);
            res = ft_strdup(holder[1]);
            stock_buffer = ft_strdup(holder[0]);
            next_line = ft_strjoin(stock_buffer, "\n");
            free(stock_buffer);
            free(holder[1]);
	        free(holder[0]);
            free(holder);
            return (next_line);
        }
        else
	        stock_buffer = ft_strjoin(stock_buffer, res);
    }
    free(res);
    while (ft_strchr(stock_buffer, '\n') == 0)
    {
        if (holder != NULL)
        {
            free(holder[0]);
            free(holder);
        }
        holder = buffer_handler(stock_buffer, fd);
        if (holder == NULL && stock_buffer == NULL)
        {
            free(stock_buffer);
            return (NULL);
        }
        else if (holder == NULL && stock_buffer[0] == '\0')
        {
            //if (res)
            //    free(res);
            free(stock_buffer);
            return (NULL);
        }
        else if (holder == NULL)
        {
            res = NULL;
            next_line = stock_buffer;
            //if (stock_buffer != NULL)
             //   free(stock_buffer);
            return (next_line);
        }
        free(stock_buffer);
        stock_buffer = ft_strdup(holder[0]);
        //res = NULL;
        //free(res);
        //printf("%d\n", ft_mat_len(holder));
        //if (sizeof(holder) == 16)
        //printf("%ld\n", sizeof(holder));
        //printf("%s\n", holder[1]);
        if (holder[1])
            res = ft_strdup(holder[1]);
        //printf("%d\n", ft_mat_len(holder));
    }
    next_line = ft_strdup(stock_buffer);
	free(holder[1]);
	free(holder[0]);
    free(holder);
    //free(res);
    free(stock_buffer);
    return (next_line);
}
