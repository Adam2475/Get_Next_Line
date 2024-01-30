/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adapassa <adapassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:19:19 by adapassa          #+#    #+#             */
/*   Updated: 2024/01/30 15:48:35 by adapassa         ###   ########.fr       */
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

static int	ft_count(char const *s, char c)
{
	int	i;
	int	sn;

	i = 0;
	sn = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			sn++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (sn);
}

static size_t	ft_superstrlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	**malloc_error(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**main_procedure(char **str, int *i, char *s, char c)
{
	while (s[++i[0]] != 0)
	{
		if (s[i[0]] != c)
		{
			str[i[1]] = ft_substr(s, i[0], ft_superstrlen(&s[i[0]], c));
			if (!str[i[1]])
				return (malloc_error(str));
			i[0] = i[0] + ft_superstrlen(&s[i[0]], c);
			break ;
		}
	}
	i[1]++;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	int		ns;
	char	**str;
	int		i[2];

	i[1] = 0;
	i[0] = -1;
	ns = ft_count(s, c);
	str = ft_calloc((ns + 1), sizeof(char *));
	if (!str)
		return (NULL);
	while (ns--)
	{
		if (main_procedure(str, i, (char *)s, c) == NULL)
			return (NULL);
	}
	str[i[1]] = 0;
	return (str);
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