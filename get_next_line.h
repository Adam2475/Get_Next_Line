/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adapassa <adapassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:58:27 by adapassa          #+#    #+#             */
/*   Updated: 2024/02/01 15:25:37 by adapassa         ###   ########.fr       */
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

char    *get_next_line(int fd);
char	**ft_minisplit(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *str, int c, size_t n);
int     ft_strlen(char *str);
void    ft_putstr(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *str, size_t n);

#endif