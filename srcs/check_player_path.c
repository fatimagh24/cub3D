/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:42:19 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/26 17:26:17 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h" 

int	flood_fill(int x, int y, char **grid, int height)
{
	if (y < 0 || y >= height)
		return (0);
	if (x < 0 || x >= (int)ft_strlen(grid[y]))
		return (0);
	if (grid[y][x] == ' ' || grid[y][x] == '\0')
		return (0);
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return (1);
	grid[y][x] = 'V';
	if (!flood_fill(x + 1, y, grid, height))
		return (0);
	if (!flood_fill(x - 1, y, grid, height))
		return (0);
	if (!flood_fill(x, y + 1, grid, height))
		return (0);
	if (!flood_fill(x, y - 1, grid, height))
		return (0);
	return (1);
}



int	is_player_path_correct(t_map *map, int px, int py)
{
	char	**copy;
	int		valid;

	copy = copy_grid(map->grid, map->height);
	if (!copy)
		return (0);
	valid = flood_fill(px, py, copy, map->height);
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
