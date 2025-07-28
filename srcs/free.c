/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:42:44 by rhasan            #+#    #+#             */
/*   Updated: 2025/07/28 13:45:12 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void	free_all(t_data *game)
// {
// 	if (!game)
// 		return;

// 	free_data(game); 
// }


void free_textures(t_data *data)
{
	if (data->north.img)
		mlx_destroy_image(data->mlx_ptr, data->north.img);
	if (data->south.img)
		mlx_destroy_image(data->mlx_ptr, data->south.img);
	if (data->east.img)
		mlx_destroy_image(data->mlx_ptr, data->east.img);
	if (data->west.img)
		mlx_destroy_image(data->mlx_ptr, data->west.img);
}

// int clean_exit(t_data *data, char *error_msg, int code)
// {
// 	if (error_msg)
// 		ft_putstr_fd(error_msg, 2);
//     if (data->north.img)
//         mlx_destroy_image(data->mlx_ptr, data->north.img);
//     if (data->south.img)
//         mlx_destroy_image(data->mlx_ptr, data->south.img);
//     if (data->east.img)
//         mlx_destroy_image(data->mlx_ptr, data->east.img);
//     if (data->west.img)
//         mlx_destroy_image(data->mlx_ptr, data->west.img);
//     if (data->img_ptr)
//         mlx_destroy_image(data->mlx_ptr, data->img_ptr);
//     if (data->win_ptr)
//         mlx_destroy_window(data->mlx_ptr, data->win_ptr);
//     return code;
// }

void	destroy_game(t_data *data)
{
	free_textures(data);
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->map != NULL)
		clean_array(data->map);
	if (data->map_data.grid)
		clean_array(data->map_data.grid);
	free(data->n_path);
	free(data->s_path);
	free(data->e_path);
	free(data->w_path);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	destroy_game_first(t_data *data)
{
	free_textures(data);
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	int i = 0;
	while (data->map[i])
	{
		if (data->map[i])
			free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data->n_path);
	free(data->s_path);
	free(data->e_path);
	free(data->w_path);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
