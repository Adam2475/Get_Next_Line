/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adapassa <adapassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:58:27 by adapassa          #+#    #+#             */
/*   Updated: 2024/02/01 19:29:47 by adapassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>

# define FALSE 0
# define TRUE 1

// typedef struct s_container
// {
// 	char		*stock_buffer;
// 	static char	*res;
// 	char		*next_line;
// 	char		**holder;
// }	t_container;

char	*get_next_line(int fd);
char	**ft_minisplit(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
//char	*ft_strchr(const char *s, int c);
void	*ft_free_mat(char **mat, char *str);
//char	*ft_strdup(const char *s);
//void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif