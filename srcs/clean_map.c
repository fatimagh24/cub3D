/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:07:40 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/27 16:11:02 by fghanem          ###   ########.fr       */
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

void	free_data(t_data *data)
{
	if (data->n_path)
		free(data->n_path);
	if (data->s_path)
		free(data->s_path);
	if (data->w_path)
		free(data->w_path);
	if (data->e_path)
		free(data->e_path);
	clean_array(data->map);
	clean_array(data->map_data.grid);
}

void	free_first(t_data *data)
{
	if (data->n_path)
		free(data->n_path);
	if (data->s_path)
		free(data->s_path);
	if (data->w_path)
		free(data->w_path);
	if (data->e_path)
		free(data->e_path);
	free(data->map);
	free_map(&data->map_data);
}

void	free_map(t_map *map)
{
	clean_array(map->grid);
}

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
