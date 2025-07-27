/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:42:44 by rhasan            #+#    #+#             */
/*   Updated: 2025/07/27 16:30:41 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void free_all(t_data *data)
{
    // int i;

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
    // i = 0; 
    // if (data->map_data.grid)
    // {
    //     while(data->map_data.grid[i])
    //         free(data->map_data.grid[i++]);
    //     free(data->map_data.grid);
    // }
    // free(data->n_path);
    // free(data->s_path);
    // free(data->e_path);
    // free(data->w_path);
}
