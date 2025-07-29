/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:18:33 by rhasan            #+#    #+#             */
/*   Updated: 2025/07/29 12:22:53 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_data *data, double speed)
{
	int	next_x;
	int	next_y;

	next_y = (int)(data->pos_y + data->dir_y * speed);
	next_x = (int)(data->pos_x + data->dir_x * speed);
	if (data->map_data.grid[(int)data->pos_y][next_x] != '1')
		data->pos_x += data->dir_x * speed;
	if (data->map_data.grid[next_y][(int)data->pos_x] != '1')
		data->pos_y += data->dir_y * speed;
}

void	move_backward(t_data *data, double speed)
{
	int	next_x;
	int	next_y;

	next_x = (int)(data->pos_x - data->dir_x * speed);
	next_y = (int)(data->pos_y - data->dir_y * speed);
	if (data->map_data.grid[(int)data->pos_y][next_x] != '1')
		data->pos_x -= data->dir_x * speed;
	if (data->map_data.grid[next_y][(int)data->pos_x] != '1')
		data->pos_y -= data->dir_y * speed;
}

void	move_right(t_data *data, double speed)
{
	int	next_x;
	int	next_y;

	next_x = (int)(data->pos_x + data->plane_x * speed);
	next_y = (int)(data->pos_y + data->plane_y * speed);
	if (data->map_data.grid[(int)data->pos_y][next_x] != '1')
		data->pos_x += data->plane_x * speed;
	if (data->map_data.grid[next_y][(int)data->pos_x] != '1')
		data->pos_y += data->plane_y * speed;
}

void	move_left(t_data *data, double speed)
{
	int	next_x;
	int	next_y;

	next_x = (int)(data->pos_x - data->plane_x * speed);
	next_y = (int)(data->pos_y - data->plane_y * speed);
	if (data->map_data.grid[(int)data->pos_y][next_x] != '1')
		data->pos_x -= data->plane_x * speed;
	if (data->map_data.grid[next_y][(int)data->pos_x] != '1')
		data->pos_y -= data->plane_y * speed;
}

void	rotate_player(t_data *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(angle) - player->plane_y
		* sin(angle);
	player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}
