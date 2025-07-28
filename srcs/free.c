/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:42:44 by rhasan            #+#    #+#             */
/*   Updated: 2025/07/28 13:00:39 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	destroy_game(t_data *data)
{
	free_textures(data);
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	clean_array(data->map);
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
