/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adapassa <adapassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:58:24 by adapassa          #+#    #+#             */
/*   Updated: 2024/02/04 19:24:11 by adapassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	if (!s)
		return (0);
	if (c == 0)
		return (str + (long int)ft_custom_function(0, 0, ((char *)s), 0));
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

static char	**buffer_handler(char **buffer, int fd)
{
	char		*tmp;
	char		**trim_result;
	char		**stock;

	tmp = (char *)ft_custom_function(sizeof(char), (BUFFER_SIZE + 1), NULL, 1);
	if (!tmp)
		return (NULL);
	if (read(fd, tmp, BUFFER_SIZE) == 0)
		return (ft_free_mat(NULL, tmp));
	trim_result = trim_buffer(tmp);
	stock = (char **)ft_custom_function(sizeof(char *), 2, NULL, 1);
	if (!stock)
		return (NULL);
	if (trim_result)
	{
		free(tmp);
		tmp = ft_strjoin(trim_result[0], "\n");
		stock[1] = ft_strdup(trim_result[1]);
		ft_free_mat(trim_result, NULL);
	}
	stock[0] = ft_strjoin(*buffer, tmp);
	free(*buffer);
	free(tmp);
	return (stock);
}

static char	*main_procedure(char **stock_buffer, char **res,
		char **holder)
{
	if (ft_strchr(*res, '\n') != 0)
	{
		holder = ft_minisplit(*res);
		free(*res);
		*res = ft_strdup(holder[1]);
		*stock_buffer = ft_strjoin(holder[0], "\n");
		ft_free_mat(holder, NULL);
		return (*stock_buffer);
	}
	*stock_buffer = ft_strjoin(NULL, *res);
	free(*res);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*stock_buffer;
	static char	*res;
	char		**holder;

	stock_buffer = NULL;
	holder = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, stock_buffer, 0) < 0)
		return (NULL);
	if (res && main_procedure(&stock_buffer, &res, holder) != NULL)
		return (stock_buffer);
	while (ft_strchr(stock_buffer, '\n') == 0)
	{
		if (holder != NULL)
			ft_free_mat(holder, NULL);
		holder = buffer_handler(&stock_buffer, fd);
		if (holder == NULL && (stock_buffer == NULL || stock_buffer[0] == '\0'))
			return (ft_free_mat(NULL, stock_buffer));
		res = NULL;
		if (holder == NULL)
			return (stock_buffer);
		stock_buffer = ft_strdup(holder[0]);
		res = ft_strdup(holder[1]);
	}
	ft_free_mat(holder, NULL);
	return (stock_buffer);
}
