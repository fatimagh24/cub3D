/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:15:22 by rhasan            #+#    #+#             */
/*   Updated: 2025/07/27 17:02:40 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int close_window(void *param)
{
    t_data *data;

    data = (t_data *)param;
    free_all(data);
    //clean_exit(data, "Window closed by user\n", 0);
    exit(0);
    return (0);
}

static void handle_movement(int keycode, t_data *data)
{
    double move_speed;

    move_speed = 0.2;
    if (keycode == XK_w)
        move_forward(data, move_speed);
    else if (keycode == XK_s)
        move_backward(data, move_speed);
    else if (keycode == XK_a)
        move_left(data, move_speed);
    else if (keycode == XK_d)
        move_right(data, move_speed);
}

static void handle_rotation(int keycode, t_data *data)
{
    double rot_speed;

    rot_speed = 0.1;
    if (keycode == XK_Right)
        rotate_player(data, rot_speed);
    else if (keycode == XK_Left)
        rotate_player(data, -rot_speed);
}

int key_press(int keycode, void *param)
{
    t_data *data;

    data = (t_data *)param;
    if (keycode == XK_Escape)
        close_window(param);
    handle_movement(keycode, data);
    handle_rotation(keycode, data);
    return (0);
}

int	mouse_move(int x, int y, void *param)
{
    (void)y;
	t_data *game;
	int delta_x;
	double rotation_angle;

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