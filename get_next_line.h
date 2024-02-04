/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adapassa <adapassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:58:27 by adapassa          #+#    #+#             */
/*   Updated: 2024/02/04 13:35:41 by adapassa         ###   ########.fr       */
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
# include <stddef.h>

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
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
void	*ft_free_mat(char **mat, char *str);
void    *ft_custom_function(size_t nmemb, size_t size, char *str, bool flag);

#endif