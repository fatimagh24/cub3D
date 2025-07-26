/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:29:48 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/26 17:18:26 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void copy_map_grid(t_data *data, int start, int total)
{
	int	i;

	data->map_data.grid = malloc(sizeof(char *) * (total - start + 1));
	if (!data->map_data.grid)
		return;
	i = 0;
	while (start < total)
	{
		data->map_data.grid[i] = ft_strdup(data->map[start]);
		start++;
		i++;
	}
	data->map_data.grid[i] = NULL;
	data->map_data.height = i;
	fix_map(data->map_data.grid);
	if (has_single_player(data->map_data.grid) == 1)
	{
		free_data(data);
		exit(1);
	}
	if (check_map(data->map_data.grid, &data->map_data) == 1)
	{
		free_data(data);
		exit(1);
	}
	find_player(data);
}

int	is_map(const char *line)
{
	while (*line == ' ')
		line++;
    if (*line == '1' || *line == '0' || *line == ' ')
        return (1);
    return (0);
}

void	find_player(t_data *data)
{
	int	y;
	char c; 

	y = 0;
	while (data->map_data.grid[y])
	{
		int x = 0;
		while (data->map_data.grid[y][x])
		{
			c = data->map_data.grid[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				data->map_data.player_x = x;
				data->map_data.player_y = y;
				data->map_data.player_dir = c;
				return;
			}
			x++;
		}
		y++;
	}
}

void	fix_map(char **temp)
{
	int	i;
	int	j;

	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (temp[i][j] == '\n')
				temp[i][j] = '\0';
			j++;
		}
		i++;
	}
}
