/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   movement_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:17:17 by rhasan            #+#    #+#             */
/*   Updated: 2025/08/11 13:04:30 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_walkable(t_data *data, double x, double y)
{
	int		left;
	int		right;
	int		top;
	int		bottom;
	double	buffer;

	buffer = 0.27;
	left = (int)(x - buffer);
	right = (int)(x + buffer);
	top = (int)(y - buffer);
	bottom = (int)(y + buffer);
	if (left < 0 || right >= data->map_data.width
		|| top < 0 || bottom >= data->map_data.height)
		return (0);
	if (data->map_data.grid[top][left] == '1' ||
			data->map_data.grid[top][right] == '1' ||
			data->map_data.grid[bottom][left] == '1' ||
			data->map_data.grid[bottom][right] == '1')
		return (0);
	return (1);
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
