/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:47:09 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/16 14:05:05 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int    main(int argc, char **argv)
{
    t_data data;
    t_map   map;
	int		i;

	if (argc != 2)
	{
		write(2, "Usage: ./cub3d map.cub\n", 24);
		return (1);
	}
    init_map(&map);
    init_data(&data, &map);
    parse_map(argv[1], &data);
    
    // Print info
	printf("1. \n NO: %s\nSO: %s\nWE: %s\nEA: %s\n",
		data.n_path, data.s_path, data.w_path, data.e_path);
	printf("F: %d,%d,%d\n", data.floor_color.r, data.floor_color.g, data.floor_color.b);
	printf("C: %d,%d,%d\n", data.ceiling_color.r, data.ceiling_color.g, data.ceiling_color.b);

	i = 0;
	while (data.map_data.grid && data.map_data.grid[i])
	{
		write(1, data.map_data.grid[i], ft_strlen(data.map_data.grid[i]));
		i++;
	}
	printf("\nPlayer: (%d, %d) facing %c\n",
		data.map_data.player_x, data.map_data.player_y, data.map_data.player_dir);
	return (0);

}
