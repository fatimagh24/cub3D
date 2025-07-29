/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:42:19 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/29 12:14:10 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_out_of_bounds(int x, int y, char **grid, int height)
{
	int	len;

	if (y < 0 || y >= height)
		return (1);
	len = (int)ft_strlen(grid[y]);
	if (x < 0 || x >= len || grid[y][x] == '\0' || grid[y][x] == '\n')
		return (1);
	return (0);
}

int	flood_fill(char **grid, int x, int y, int height)
{
	if (is_out_of_bounds(x, y, grid, height))
		return (1);
	if (grid[y][x] == ' ' || grid[y][x] == '\n')
		return (1);
	if (!is_walkable(grid[y][x]))
		return (0);
	grid[y][x] = 'x';
	if (flood_fill(grid, x + 1, y, height))
		return (1);
	if (flood_fill(grid, x - 1, y, height))
		return (1);
	if (flood_fill(grid, x, y + 1, height))
		return (1);
	if (flood_fill(grid, x, y - 1, height))
		return (1);
	return (0);
}

int	is_player_path_correct(t_map *map, int px, int py)
{
	char	**copy;
	int		valid;

	copy = copy_grid(map->grid, map->height);
	if (!copy)
		return (0);
	valid = flood_fill(copy, px, py, map->height);
	free_grid(copy);
	return (valid);
}

char	**copy_grid(char **grid, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
