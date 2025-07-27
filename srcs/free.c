/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:42:44 by rhasan            #+#    #+#             */
/*   Updated: 2025/07/27 16:47:03 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_all(t_data *game)
{
	if (!game)
		return;

	free_data(game);

	free(game); 
}


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

int clean_exit(t_data *data, char *error_msg, int code)
{
	if (error_msg)
		ft_putstr_fd(error_msg, 2);
	free_data(data);
	exit(code);
	return (code);

    if (data->north.img)
        mlx_destroy_image(data->mlx_ptr, data->north.img);
    if (data->south.img)
        mlx_destroy_image(data->mlx_ptr, data->south.img);
    if (data->east.img)
        mlx_destroy_image(data->mlx_ptr, data->east.img);
    if (data->west.img)
        mlx_destroy_image(data->mlx_ptr, data->west.img);
    if (data->img_ptr)
        mlx_destroy_image(data->mlx_ptr, data->img_ptr);
    if (data->win_ptr)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}
