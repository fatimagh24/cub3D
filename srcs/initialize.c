/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:28:09 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/26 17:38:45 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_data(t_data *data, t_map *map)
{
    data->mlx_ptr = NULL;
    data->win_ptr = NULL;
    data->height = 0;
    data->map = NULL;
    data->map = malloc(sizeof(char *) * 100);
    if (!data->map)
	{
        ft_putstr_fd("Memory allocation failed\n", 2);
		exit(1);
	}
    data->player_dir = 0.0;
    data->e_path = NULL;
    data->n_path = NULL;
    data->s_path = NULL;
    data->w_path = NULL;
    data->floor_color = (t_color){-1, -1, -1};
	data->ceiling_color = (t_color){-1, -1, -1};
    data->map_data = *map;
}

void init_map(t_map *map)
{
    map->grid = NULL;
    map->player_x = -1;
    map->player_y = -1;
    map->player_dir = '\0';
    map->height = 0;
}
