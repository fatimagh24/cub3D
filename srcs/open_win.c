/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:16:52 by rhasan            #+#    #+#             */
/*   Updated: 2025/07/28 10:12:54 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void load_texture(t_data *data, t_texture *tex, char *path)
{
    tex->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &tex->width, &tex->height);
    if (!tex->img)
    {
        fprintf(stderr, "Error: Failed to load texture from path: %s\n", path);
        destroy_game(data);
        exit(1);
    }
    tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len, &tex->endian);
}

void init_window(t_data *game, char *map_file)
{
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
    {
        destroy_game(game);
        exit(1);
    }
    game->win_ptr = mlx_new_window(game->mlx_ptr, game->width, game->height, "Cub3D");
    if (!game->win_ptr)
    {
        destroy_game(game);
        exit(1);
    }
    if (parse_map(map_file, game))
    {
        destroy_game(game);
        exit(1);
    }
    init_player(game);
    game->img_ptr = mlx_new_image(game->mlx_ptr, game->width, game->height);
    game->img_data = mlx_get_data_addr(game->img_ptr, &game->bpp, &game->line_len, &game->endian);
    load_texture(game, &game->north, game->n_path);
    load_texture(game, &game->south, game->s_path);
    load_texture(game, &game->east, game->e_path);
    load_texture(game, &game->west, game->w_path);
    mlx_hook(game->win_ptr, 2, 1L << 0, key_press, game);
    mlx_hook(game->win_ptr, 17, 0, close_window, game);
    mlx_loop_hook(game->mlx_ptr, render_frame, game);
    mlx_hook(game->win_ptr, 6, 1L << 6, mouse_move, game);
    mlx_loop(game->mlx_ptr);
}
