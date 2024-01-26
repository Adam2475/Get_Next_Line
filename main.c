/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adapassa <adapassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:00:00 by adapassa          #+#    #+#             */
/*   Updated: 2024/01/26 13:06:05 by adapassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    int fd;
    char *tmp;
    fd = open("42_with_nl", O_RDONLY);
    while (1)
    {
        tmp = get_next_line(fd);
        if (tmp)
            ft_putstr(tmp);
        if (!tmp)
            break ;
        free(tmp);
    }
    close(fd);
    return 0;
}