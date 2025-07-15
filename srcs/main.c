/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:38:03 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/15 15:22:34 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int    main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_putstr_fd("Error: Incorrect number of arguments\n", 2);
        return (1);
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        ft_putstr_fd("Error: Could not open file\n", 2);
        return (1);
    }
    char *line;
    int i = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        if (line[0] == '\0')
        {
            free(line);
            continue;
        }
        printf("Line %d: %s\n", i++, line);
        free(line);
        line = get_next_line(fd);
    }
    return (0);
}