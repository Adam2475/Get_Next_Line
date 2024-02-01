/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adapassa <adapassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:19:19 by adapassa          #+#    #+#             */
/*   Updated: 2024/02/01 19:21:53 by adapassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_free_mat(char **mat, char *str)
{
	if (str == NULL)
	{
		if (mat[1] != NULL)
			free(mat[1]);
		free(mat[0]);
		free(mat);
	}
	else if (mat == NULL)
		free(str);
	else if ((mat != NULL) && (str != NULL))
	{
		free(mat[1]);
		free(mat[0]);
		free(mat);
		free(str);
	}
	else if (!mat && !str)
		return (NULL);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*ptr;
	size_t		i;

	ptr = malloc(nmemb * size);
	i = 0;
	if (!ptr)
		return (NULL);
	while (i < (nmemb * size))
		ptr[i++] = 0;
	return ((void *)ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s3 = (char *)calloc(sizeof(char),
			(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
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

/////////////////////////////////////////////////////////////////////////////

char	**ft_minisplit(char *str)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	tmp = (char **)ft_calloc(sizeof(char *), 2);
	while (str[i] != '\n')
		i++;
	tmp[0] = (char *)ft_calloc(sizeof(char), i + 1);
	i = 0;
	while (str[i] != '\0')
		i++;
	tmp[1] = ft_calloc(sizeof(char), i + 1);
	i = -1;
	while (str[++i] != '\n')
		tmp[0][i] = str[i];
	tmp[0][i] = '\0';
	j = i + 1;
	i = 0;
	while (str[j] != '\0')
		tmp[1][i++] = str[j++];
	tmp[1][i] = '\0';
	return (tmp);
}

//////////////////////////////////////////////////////////////////////
