/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:29:48 by fghanem           #+#    #+#             */
/*   Updated: 2025/08/10 17:21:39 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

static int	is_valid_map(t_data *data)
{
	if (data->map_data.height <= 2)
	{
		ft_putstr_fd("Error: Map is too small\n", 2);
		return (1);
	}
	if (map_not_last(data->map_data.grid) == 1)
		return (1);
	fix_map(data->map_data.grid);
	if (has_single_player(data->map_data.grid))
		return (1);
	if (check_map(data->map_data.grid, &data->map_data))
		return (1);
	if (check_map_content(data->map_data.grid, 0))
	{
		ft_putstr_fd("Error: wrong char in map\n", 2);
		return (1);
	}
	find_player(data);
	return (0);
}

int	copy_map_grid(t_data *data, int start, int total)
{
	int	i;
	int	len;

	data->map_data.grid = malloc(sizeof(char *) * (total - start + 1));
	if (!data->map_data.grid)
		return (1);
	i = 0;
	len = 0;
	while (start < total)
	{
		data->map_data.grid[i] = ft_strdup(data->map[start]);
		if (!data->map_data.grid[i])
			return (1);
		len = ft_strlen(data->map[start]);
		if (len > data->map_data.width)
			data->map_data.width = len;
		start++;
		i++;
	}
	data->map_data.grid[i] = NULL;
	data->map_data.height = i;
	if (is_valid_map(data))
		return (1);
	return (0);
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
	int		y;
	char	c;
	int		x;

	y = 0;
	while (data->map_data.grid[y])
	{
		x = 0;
		while (data->map_data.grid[y][x])
		{
			c = data->map_data.grid[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				data->map_data.player_x = x;
				data->map_data.player_y = y;
				data->map_data.player_dir = c;
				return ;
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