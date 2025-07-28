/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:07:40 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/28 10:06:24 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void    clean_array(char **arr)
{
    int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// void	destroy_window(t_data *game)
// {
// 	if (game->img_ptr)
// 		mlx_destroy_image(game->mlx_ptr, game->img_ptr);
// 	if (game->north.img)
// 		mlx_destroy_image(game->mlx_ptr, game->north.img);
// 	if (game->south.img)
// 		mlx_destroy_image(game->mlx_ptr, game->south.img);
// 	if (game->east.img)
// 		mlx_destroy_image(game->mlx_ptr, game->east.img);
// 	if (game->west.img)
// 		mlx_destroy_image(game->mlx_ptr, game->west.img);
// 	if (game->win_ptr)
// 		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
// 	if (game->mlx_ptr)
// 		free(game->mlx_ptr);
// }
// void	free_data(t_data *data)
// {
// 	destroy_window(data);

// 	free(data->n_path);
// 	free(data->s_path);
// 	free(data->e_path);
// 	free(data->w_path);

// 	if (data->map)
// 		clean_array(data->map);
// 	if (data->map_data.grid)
// 		clean_array(data->map_data.grid);
// }



// void	free_first(t_data *data)
// {
// 	if (data->n_path)
// 		free(data->n_path);
// 	if (data->s_path)
// 		free(data->s_path);
// 	if (data->w_path)
// 		free(data->w_path);
// 	if (data->e_path)
// 		free(data->e_path);
// 	free(data->map);
// 	free_map(&data->map_data);
// }

// void	free_map(t_map *map)
// {
// 	clean_array(map->grid);
// }

void	free_grid(char **grid)
{
	int	i;

    i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
