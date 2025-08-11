/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:15:22 by rhasan            #+#    #+#             */
/*   Updated: 2025/08/11 13:09:01 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	destroy_game(data);
	exit(0);
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == XK_Escape)
		close_window(param);
	else if (keycode == XK_w)
		data->move_forward = 1;
	else if (keycode == XK_s)
		data->move_backward = 1;
	else if (keycode == XK_a)
		data->move_left = 1;
	else if (keycode == XK_d)
		data->move_right = 1;
	else if (keycode == XK_Left)
		data->rotate_left = 1;
	else if (keycode == XK_Right)
		data->rotate_right = 1;
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == XK_w)
		data->move_forward = 0;
	else if (keycode == XK_s)
		data->move_backward = 0;
	else if (keycode == XK_a)
		data->move_left = 0;
	else if (keycode == XK_d)
		data->move_right = 0;
	else if (keycode == XK_Left)
		data->rotate_left = 0;
	else if (keycode == XK_Right)
		data->rotate_right = 0;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_data	*game;
	int		delta_x;
	double	rotation_angle;

	(void)y;
	game = (t_data *)param;
	if (!game->mouse_captured)
	{
		game->last_mouse_x = x;
		game->mouse_captured = 1;
		return (0);
	}
	delta_x = x - game->last_mouse_x;
	rotation_angle = delta_x * MOUSE_SENSITIVITY;
	if (rotation_angle != 0)
		rotate_player(game, rotation_angle);
	game->last_mouse_x = x;
	return (0);
}
