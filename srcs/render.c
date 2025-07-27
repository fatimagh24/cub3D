/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:24:10 by rhasan            #+#    #+#             */
/*   Updated: 2025/07/27 16:29:31 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_player(t_data *data)
{
    int x = data->map_data.player_x;
    int y = data->map_data.player_y;
    char dir = data->map_data.player_dir;

    data->pos_x = x + 0.5;
    data->pos_y = y + 0.5;

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
    else if (dir == 'E')
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

void put_pixel(t_data *data, int x, int y, int color)
{
    char *dst;
    if (x < 0 || x >= data->width || y < 0 || y >= data->height)
        return;
    dst = data->img_data + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
}

int render_frame(t_data *data)
{
    int x, y;

    int ceiling_color = (data->ceiling_color.r << 16) |
                        (data->ceiling_color.g << 8) |
                        (data->ceiling_color.b);

    int floor_color = (data->floor_color.r << 16) |
                    (data->floor_color.g << 8) |
                    (data->floor_color.b);

    // 🎨 ارسم السماء والأرض
    for (y = 0; y < data->height / 2; y++)
        for (x = 0; x < data->width; x++)
            put_pixel(data, x, y, ceiling_color);
    for (; y < data->height; y++)
        for (x = 0; x < data->width; x++)
            put_pixel(data, x, y, floor_color);

    // 🧱 Raycasting
    for (x = 0; x < data->width; x++)
    {
        double camera_x = 2 * x / (double)data->width - 1;
        double ray_dir_x = data->dir_x + data->plane_x * camera_x;
        double ray_dir_y = data->dir_y + data->plane_y * camera_x;

        int map_x = (int)data->pos_x;
        int map_y = (int)data->pos_y;

        double delta_dist_x = fabs(1 / ray_dir_x);
        double delta_dist_y = fabs(1 / ray_dir_y);
        double side_dist_x, side_dist_y;
        double perp_wall_dist;

        int step_x, step_y;
        int hit = 0, side;

        // حساب الخطوات والمسافات
        if (ray_dir_x < 0)
        {
            step_x = -1;
            side_dist_x = (data->pos_x - map_x) * delta_dist_x;
        }
        else
        {
            step_x = 1;
            side_dist_x = (map_x + 1.0 - data->pos_x) * delta_dist_x;
        }
        if (ray_dir_y < 0)
        {
            step_y = -1;
            side_dist_y = (data->pos_y - map_y) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = (map_y + 1.0 - data->pos_y) * delta_dist_y;
        }

        // DDA
        while (!hit)
        {
            if (side_dist_x < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                map_x += step_x;
                side = 0;
            }
            else
            {
                side_dist_y += delta_dist_y;
                map_y += step_y;
                side = 1;
            }

            // 🔒 SAFETY FIRST — bounds check before accessing
            if (map_y < 0 || map_y >= data->map_data.height ||
                map_x < 0 || map_x >= data->map_data.width)
            {
                hit = 1;
                break;  // don't return immediately, just exit DDA safely
            }

            if (data->map_data.grid[map_y][map_x] == '1')
                hit = 1;
        }


        // حساب المسافة
        if (side == 0)
            perp_wall_dist = (side_dist_x - delta_dist_x);
        else
            perp_wall_dist = (side_dist_y - delta_dist_y);

        int line_height = (int)(data->height / perp_wall_dist);
        int draw_start = -line_height / 2 + data->height / 2;
        int draw_end = line_height / 2 + data->height / 2;
        if (draw_start < 0) draw_start = 0;
        if (draw_end >= data->height) draw_end = data->height - 1;

        // ✨ اختيار التكستشر المناسب
        t_texture *tex;
        if (side == 0 && ray_dir_x > 0)
            tex = &data->west;
        else if (side == 0 && ray_dir_x < 0)
            tex = &data->east;
        else if (side == 1 && ray_dir_y > 0)
            tex = &data->north;
        else
            tex = &data->south;

        // 🧮 حساب إحداثيات X على التكستشر
        double wall_x = (side == 0)
                        ? data->pos_y + perp_wall_dist * ray_dir_y
                        : data->pos_x + perp_wall_dist * ray_dir_x;
        wall_x -= floor(wall_x);
        int tex_x = (int)(wall_x * tex->width);
        if ((side == 0 && ray_dir_x > 0) || (side == 1 && ray_dir_y < 0))
            tex_x = tex->width - tex_x - 1;

        // 🖼️ نسخ البكسلات من التكستشر للصورة
        for (y = draw_start; y <= draw_end; y++)
        {
            int d = (y - draw_start) * 256;
            int tex_y = (d * tex->height) / line_height / 256;

            char *tex_pixel = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
            int color = *(unsigned int *)tex_pixel;

            put_pixel(data, x, y, color);
        }
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);

    return 0;
}

