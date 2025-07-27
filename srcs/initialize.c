/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:15:31 by rhasan            #+#    #+#             */
/*   Updated: 2025/07/27 17:00:58 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_data(t_data *data, t_map *map)
{
    data->mlx_ptr = NULL;
    data->win_ptr = NULL;
    data->width = 1600;
    data->height = 800;
    data->map = NULL;
    data->map = malloc(sizeof(char *) * 100);
    if (!data->map)
	{
        perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	data->player_x = -1;
    data->player_y = -1;
    data->player_dir = 0.0;
    data->e_path = NULL;
    data->n_path = NULL;
    data->s_path = NULL;
    data->w_path = NULL;
	data->mouse_captured = 0;
	data->last_mouse_x = 0;
    data->floor_color = (t_color){-1, -1, -1};
	data->ceiling_color = (t_color){-1, -1, -1};
    data->map_data = *map;
    data->img_ptr= NULL;
    data->img_data = NULL;
    data->bpp = 0;
    data->line_len = 0;
    data->endian = 0;
    data->north = (t_texture){NULL, NULL, 0, 0, 0, 0, 0};
    data->south = (t_texture){NULL, NULL, 0, 0, 0, 0, 0};
    data->east = (t_texture){NULL, NULL, 0, 0, 0, 0, 0};
    data->west = (t_texture){NULL, NULL, 0, 0, 0, 0, 0};
    data->pos_x = 0.0;
    data->pos_y = 0.0;
    data->dir_x = 0.0;
    data->dir_y = 0.0;
    data->plane_x = 0.0;
    data->plane_y = 0.0;
}

void init_map(t_map *map)
{
    map->grid = NULL;
    map->width = 0;
    map->player_x = -1;
    map->player_y = -1;
    map->player_dir = '\0';
    map->height = 0;
}