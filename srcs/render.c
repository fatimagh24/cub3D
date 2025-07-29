/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:24:10 by rhasan            #+#    #+#             */
/*   Updated: 2025/07/29 12:29:58 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	dst = data->img_data + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	draw_ceiling(t_data *data)
{
	int	x;
	int	y;
	int	color;

	color = (data->ceiling_color.r << 16)
		| (data->ceiling_color.g << 8) | (data->ceiling_color.b);
	y = 0;
	while (y < data->height / 2)
	{
		x = 0;
		while (x < data->width)
		{
			put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_floor(t_data *data)
{
	int	x;
	int	y;
	int	color;

	color = (data->floor_color.r << 16)
		| (data->floor_color.g << 8) | (data->floor_color.b);
	y = data->height / 2;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}

int	render_frame(t_data *data)
{
	draw_ceiling(data);
	draw_floor(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}
