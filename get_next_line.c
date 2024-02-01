/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adapassa <adapassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:58:24 by adapassa          #+#    #+#             */
/*   Updated: 2024/02/01 19:34:35 by adapassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strdup(const char *src)
{
	char	*dest;
	int		l;
	size_t	i;

	i = -1;
	if (!src)
		return (NULL);
	l = ft_strlen((char *)src);
	dest = malloc(sizeof(char) * (l + 1));
	if (!src)
		return (0);
	if (!dest)
		return (0);
	while (++i <= (size_t)l)
		((char *)dest)[i] = ((char *)src)[i];
	dest[l] = '\0';
	return (dest);
}

static char	*ft_strchr(const char *s, int c)
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

char	**trim_buffer(char *str)
{
	int		i;
	char	**tmp;

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

static char	**buffer_handler(char *buffer, int fd)
{
	char		*tmp;
	char		**trim_result;
	char		**stock;

	tmp = (char *)calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	tmp[ft_strlen(tmp)] = '\0';
	if (read(fd, tmp, BUFFER_SIZE) == 0)
		return (ft_free_mat(NULL, tmp));
	trim_result = trim_buffer(tmp);
	stock = (char **)calloc(sizeof(char *), 2);
	if (!stock)
		return (NULL);
	if (trim_result)
	{
		free(tmp);
		tmp = ft_strjoin(trim_result[0], "\n");
		stock[1] = ft_strdup(trim_result[1]);
		ft_free_mat(trim_result, NULL);
	}
	stock[0] = ft_strjoin(buffer, tmp);
	free(tmp);
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*stock_buffer;
	static char	*res;
	char		*next_line;
	char		**holder;

	next_line = NULL;
	stock_buffer = NULL;
	holder = NULL;
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
			ft_free_mat(holder, stock_buffer);
			return (next_line);
		}
		else
			stock_buffer = ft_strjoin(stock_buffer, res);
	}
	free(res);
	while (ft_strchr(stock_buffer, '\n') == 0)
	{
		if (holder != NULL)
			ft_free_mat(holder, NULL);
		holder = buffer_handler(stock_buffer, fd);
		if (holder == NULL && stock_buffer == NULL)
		{
			free(stock_buffer);
			return (NULL);
		}
		else if (holder == NULL && stock_buffer[0] == '\0')
		{
			free(stock_buffer);
			return (NULL);
		}
		else if (holder == NULL)
		{
			res = NULL;
			next_line = stock_buffer;
			return (next_line);
		}
		free(stock_buffer);
		stock_buffer = ft_strdup(holder[0]);
		if (holder[1])
			res = ft_strdup(holder[1]);
	}
	next_line = ft_strdup(stock_buffer);
	ft_free_mat(holder, stock_buffer);
	return (next_line);
}
