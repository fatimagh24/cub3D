/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:20:18 by rhasan            #+#    #+#             */
/*   Updated: 2025/08/10 15:55:01 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_player_dir_ew(t_data *data, char dir)
{
	if (dir == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
}

static void	set_player_dir_ns(t_data *data, char dir)
{
	if (dir == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	else if (dir == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
}

void	init_player(t_data *data)
{
	char	dir;
	int		x;
	int		y;

	dir = data->map_data.player_dir;
	y = data->map_data.player_y;
	x = data->map_data.player_x;
	data->pos_x = x + 0.5;
	data->pos_y = y + 0.5;
	if (dir == 'N' || dir == 'S')
		set_player_dir_ns(data, dir);
	else if (dir == 'E' || dir == 'W')
		set_player_dir_ew(data, dir);
}
