/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adapassa <adapassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:00:00 by adapassa          #+#    #+#             */
/*   Updated: 2024/02/04 17:19:02 by adapassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    int fd;
    char *tmp;
    fd = open("multiple_nlx5", O_RDONLY);
    while (1)
    {
        tmp = get_next_line(fd);
        if (tmp)
            printf("%s\n", tmp);
        if (!tmp)
            break ;
        free(tmp);
    }
    close(fd);
    //ft_putstr("\n/////////////////////////////////////////////\n");
    // fd = open("41_with_nl", O_RDONLY);
    // while (1)
    // {
    //      tmp = get_next_line(fd);
    //      if (tmp)
    //          ft_putstr(tmp);
    //      if (!tmp)
    //          break ;
    //      free(tmp);
    // }
    // ft_putstr("\n/////////////////////////////////////////////\n");
    // close(fd);
    // fd = open("42_no_nl", O_RDONLY);
    // while (1)
    // {
    //     tmp = get_next_line(fd);
    //     if (tmp)
    //         ft_putstr(tmp);
    //     if (!tmp)
    //         break ;
    //     free(tmp);
    // }
    // ft_putstr("\n/////////////////////////////////////////////\n");
    // close(fd);
    // fd = open("43_with_nl", O_RDONLY);
    // while (1)
    // {
    //     tmp = get_next_line(fd);
    //     if (tmp)
    //         ft_putstr(tmp);
    //     if (!tmp)
    //         break ;
    //     free(tmp);
    // }
    // ft_putstr("\n/////////////////////////////////////////////\n");
    // close(fd);
    // fd = open("43_no_nl", O_RDONLY);
    // while (1)
    // {
    //     tmp = get_next_line(fd);
    //     if (tmp)
    //         ft_putstr(tmp);
    //     if (!tmp)
    //         break ;
    //     free(tmp);
    // }
    // ft_putstr("\n/////////////////////////////////////////////\n");
    // close(fd);
    // fd = open("multiple_line_no_nl", O_RDONLY);
    // while (1)
    // {
    //     tmp = get_next_line(fd);
    //     if (tmp)
    //         ft_putstr(tmp);
    //     if (!tmp)
    //         break ;
    //     free(tmp);
    // }
    // ft_putstr("\n/////////////////////////////////////////////\n");
    // close(fd);
    // fd = open("alternate_line_nl_no_nl", O_RDONLY);
    // while (1)
    // {
    //     tmp = get_next_line(fd);
    //     if (tmp)
    //         ft_putstr(tmp);
    //     if (!tmp)
    //         break ;
    //     free(tmp);
    // }
    // ft_putstr("\n/////////////////////////////////////////////\n");
    // close(fd);
    // fd = open("alternate_line_nl_with_nl", O_RDONLY);
    // while (1)
    // {
    //     tmp = get_next_line(fd);
    //     if (tmp)
    //         ft_putstr(tmp);
    //     if (!tmp)
    //         break ;
    //     free(tmp);
    // }
    // ft_putstr("\n/////////////////////////////////////////////\n");
    // close(fd);
    // fd = open("big_line_no_nl", O_RDONLY);
    // while (1)
    // {
    //     tmp = get_next_line(fd);
    //     if (tmp)
    //         ft_putstr(tmp);
    //     if (!tmp)
    //         break ;
    //     free(tmp);
    // }
    // ft_putstr("\n/////////////////////////////////////////////\n");
    // close(fd);
    // fd = open("big_line_with_nl", O_RDONLY);
    // while (1)
    // {
    //     tmp = get_next_line(fd);
    //     if (tmp)
    //         ft_putstr(tmp);
    //     if (!tmp)
    //         break ;
    //     free(tmp);
    // }
    // ft_putstr("\n/////////////////////////////////////////////\n");
    // close(fd);
    // fd = open("multiple_line_no_nl", O_RDONLY);
    // while (1)
    // {
    //     tmp = get_next_line(fd);
    //     if (tmp)
    //         ft_putstr(tmp);
    //     if (!tmp)
    //         break ;
    //     free(tmp);
    // }
    // ft_putstr("\n/////////////////////////////////////////////\n");
    // close(fd);
    // fd = open("multiple_line_with_nl", O_RDONLY);
    // while (1)
    // {
    //     tmp = get_next_line(fd);
    //     if (tmp)
    //         ft_putstr(tmp);
    //     if (!tmp)
    //         break ;
    //     free(tmp);
    // }
    // ft_putstr("\n/////////////////////////////////////////////\n");
    // close(fd);
    // fd = open("empty", O_RDONLY);
    // while (1)
    // {
    //     tmp = get_next_line(fd);
    //     if (tmp)
    //         ft_putstr(tmp);
    //     if (!tmp)
    //         break ;
    //     free(tmp);
    // }
    // ft_putstr("\n/////////////////////////////////////////////\n");
    // close(fd);
    // fd = open("nl", O_RDONLY);
    // while (1)
    // {
    //     tmp = get_next_line(fd);
    //     if (tmp)
    //         ft_putstr(tmp);
    //     if (!tmp)
    //         break ;
    //     free(tmp);
    // }
    // ft_putstr("\n/////////////////////////////////////////////\n");
    // close(fd);
    // fd = open("multiple_nlx5v", O_RDONLY);
    // while (1)
    // {
    //     tmp = get_next_line(fd);
    //     if (tmp)
    //         ft_putstr(tmp);
    //     if (!tmp)
    //         break ;
    //     free(tmp);
    // }
    // ft_putstr("\n/////////////////////////////////////////////\n");
    // fd = open("one_line_no_nl", O_RDONLY);
    // while (1)
    // {
    //     tmp = get_next_line(fd);
    //     if (tmp)
    //         ft_putstr(tmp);
    //     if (!tmp)
    //         break ;
    //     free(tmp);
    // }
    // ft_putstr("\n/////////////////////////////////////////////\n");
    return 0;
}
