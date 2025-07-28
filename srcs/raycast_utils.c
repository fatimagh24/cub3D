/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:57:50 by rhasan            #+#    #+#             */
/*   Updated: 2025/07/28 13:07:53 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void calc_line_dimensions(t_data *data, t_ray *ray)
{
    if (ray->side == 0)
        ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
    else
        ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
    ray->line_height = (int)(data->height / ray->perp_wall_dist);
    ray->draw_start = -ray->line_height / 2 + data->height / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + data->height / 2;
    if (ray->draw_end >= data->height)
        ray->draw_end = data->height - 1;
}

void choose_texture(t_data *data, t_ray *ray)
{
    if (ray->side == 0 && ray->ray_dir_x > 0)
        ray->tex = &data->west;
    else if (ray->side == 0 && ray->ray_dir_x < 0)
        ray->tex = &data->east;
    else if (ray->side == 1 && ray->ray_dir_y > 0)
        ray->tex = &data->north;
    else
        ray->tex = &data->south;
}

void calc_tex_x(t_data *data, t_ray *ray)
{
    if (ray->side == 0)
        ray->wall_x = data->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
    else
        ray->wall_x = data->pos_x + ray->perp_wall_dist * ray->ray_dir_x;

    ray->wall_x -= floor(ray->wall_x);
    ray->tex_x = (int)(ray->wall_x * ray->tex->width);
    if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1 && ray->ray_dir_y < 0))
        ray->tex_x = ray->tex->width - ray->tex_x - 1;
}

void draw_vertical_line(t_data *data, t_ray *ray, int x)
{
    int y;
    int d;
    int tex_y;
    char *tex_pixel;
    int color;

    y = ray->draw_start;
    while (y <= ray->draw_end)
    {
        d = (y - ray->draw_start) * 256;
        tex_y = (d * ray->tex->height) / ray->line_height / 256;
        tex_pixel = ray->tex->addr + (tex_y * ray->tex->line_len
                        + ray->tex_x * (ray->tex->bpp / 8));
        color = *(unsigned int *)tex_pixel;
        put_pixel(data, x, y, color);
        y++;
    }
}