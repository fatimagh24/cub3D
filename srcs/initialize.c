/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:15:31 by rhasan            #+#    #+#             */
/*   Updated: 2025/08/10 16:23:49 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_color(t_color *color)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
}

static void	init_texture(t_texture *tex)
{
	tex->img = NULL;
	tex->addr = NULL;
	tex->width = 0;
	tex->height = 0;
	tex->bpp = 0;
	tex->line_len = 0;
	tex->endian = 0;
}

static void	init_all_settings(t_data *data)
{
	data->player_x = -1;
	data->player_y = -1;
	data->player_dir = 0.0;
	init_color(&data->floor_color);
	init_color(&data->ceiling_color);
	data->mouse_captured = 0;
	data->last_mouse_x = 0;
	data->pos_x = 0.0;
	data->pos_y = 0.0;
	data->dir_x = 0.0;
	data->dir_y = 0.0;
	data->plane_x = 0.0;
	data->plane_y = 0.0;
	data->img_ptr = NULL;
	data->img_data = NULL;
	data->bpp = 0;
	data->line_len = 0;
	data->endian = 0;
	data->move_forward = 0;
    data->move_backward = 0;
    data->move_left = 0;
    data->move_right = 0;
    data->rotate_left = 0;
    data->rotate_right = 0;
	init_texture(&data->north);
	init_texture(&data->south);
	init_texture(&data->east);
	init_texture(&data->west);
}

void	init_data(t_data *data, t_map *map)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->width = 1600;
	data->height = 800;
	data->map = malloc(sizeof(char *) * 100);
	if (!data->map)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	data->map_data = *map;
	data->e_path = NULL;
	data->n_path = NULL;
	data->s_path = NULL;
	data->w_path = NULL;
	init_all_settings(data);
}

void	init_map(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->player_x = -1;
	map->player_y = -1;
	map->player_dir = '\0';
	map->height = 0;
}
