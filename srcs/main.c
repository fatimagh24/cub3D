/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:38:03 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/27 16:11:13 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **argv)
{
    t_data data;
    t_map   map;

    if (ac != 2 || ac < 2)
    {
        ft_putstr_fd("Usage: ./cub3d map.cub\n", 2);
        return (1);
    }
    if (ft_strlen(argv[1]) < 4 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
	{
		write(2, "Error: Map file must have a .cub extension\n", 43);
		return (1);
	}
	if (check_valid_map(argv[1]))
    {
        clean_exit(&data, "Error: Invalid map config\n", 1);
		return (1);
    }
    init_map(&map);
    init_data(&data, &map);
    init_window(&data, argv[1]);
    free_all(&data);
    return (0);
}