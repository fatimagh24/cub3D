/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:18:33 by rhasan            #+#    #+#             */
/*   Updated: 2025/08/10 16:48:23 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_data *data, double speed)
{
	double	new_x;
	double	new_y;

	new_x = data->pos_x + data->dir_x * speed;
	new_y = data->pos_y + data->dir_y * speed;
	if (is_walkable(data, new_x, new_y))
	{
		data->pos_x = new_x;
		data->pos_y = new_y;
	}
}

void	move_backward(t_data *data, double speed)
{
	double	new_x;
	double	new_y;

	new_x = data->pos_x - data->dir_x * speed;
	new_y = data->pos_y - data->dir_y * speed;
	if (is_walkable(data, new_x, new_y))
	{
		data->pos_x = new_x;
		data->pos_y = new_y;
	}
}

void	move_right(t_data *data, double speed)
{
	double	new_x;
	double	new_y;

	new_x = data->pos_x + data->plane_x * speed;
	new_y = data->pos_y + data->plane_y * speed;
	if (is_walkable(data, new_x, new_y))
	{
		data->pos_x = new_x;
		data->pos_y = new_y;
	}
}

void	move_left(t_data *data, double speed)
{
	double	new_x;
	double	new_y;

	new_x = data->pos_x - data->plane_x * speed;
	new_y = data->pos_y - data->plane_y * speed;
	if (is_walkable(data, new_x, new_y))
	{
		data->pos_x = new_x;
		data->pos_y = new_y;
	}
}
