/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adapassa <adapassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:19:19 by adapassa          #+#    #+#             */
/*   Updated: 2024/02/01 13:22:06 by adapassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)str)[i++] = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset ((unsigned char *)ptr, 0, nmemb * size);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen((char *)s))
	{
		sub_str = ft_calloc(sizeof(char), 1);
		return (sub_str);
	}
	if (ft_strlen((char *)s) - start > len)
		sub_str = malloc(sizeof(char) * ((len + 1)));
	else
		sub_str = malloc(sizeof(char)
				* (((unsigned int)ft_strlen((char *)s) - start) + 1));
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	while ((char)s[start] && (size_t)i < len)
	{
		sub_str[i++] = (char)s[start];
		start++;
	}
	sub_str[i] = 0;
	return (sub_str);
}

/////////////////////////////////////////////////////////////////////////////

char	**ft_minisplit(char *str)
{
	char **tmp;
	int i;
	int j;
	i = 0;
	tmp = (char **)ft_calloc(sizeof(char*), 2);
	if (!tmp)
		return (NULL);
	if (!str)
		return (NULL);
	while (str[i] != '\n')
		i++;
	tmp[0] = (char *)ft_calloc(sizeof(char), i + 1);
	i = 0;
	while (str[i] != '\0')
		i++;
	tmp[1] = ft_calloc(sizeof(char), i + 1);
	i = 0;
	while (str[i] != '\n')
	{
		tmp[0][i] = str[i];
		i++;
	}
	tmp[0][i] = '\0';
	j = i + 1;
	i = 0;
	while (str[j] != '\0')
	{
		tmp[1][i] = str[j];
		i++;
		j++;
	}
	tmp[1][i] = '\0';
	return (tmp);
}

//////////////////////////////////////////////////////////////////////

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = str;
	while (i < n)
		ptr[i++] = c;
	return ((void *)ptr);
}