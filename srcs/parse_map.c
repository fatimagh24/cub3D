/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:27:43 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/24 17:16:05 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_data(t_data *data, t_map *map)
{
    data->mlx_ptr = NULL;
    data->win_ptr = NULL;
    data->height = 0;
    data->map = NULL;
    data->map = malloc(sizeof(char *) * 100);
    if (!data->map)
	{
        ft_putstr_fd("Memory allocation failed\n", 2);
		exit(1);
	}
	data->player_x = -1;
    data->player_y = -1;
    data->player_dir = 0.0;
    data->e_path = NULL;
    data->n_path = NULL;
    data->s_path = NULL;
    data->w_path = NULL;
    data->floor_color = (t_color){-1, -1, -1};
	data->ceiling_color = (t_color){-1, -1, -1};
    data->map_data = *map;
}

void init_map(t_map *map)
{
    map->grid =  malloc(sizeof(char *) * 100);
	if (!map->grid)
	{
        ft_putstr_fd("Memory allocation failed\n", 2);
		exit(1);
	}
    map->player_x = -1;
    map->player_y = -1;
    map->player_dir = '\0';
    map->height = 0;
}


static int	is_map(const char *line)
{
	while (*line == ' ')
		line++;
    if (*line == '1' || *line == '0' || *line == ' ')
        return (1);
    return (0);
}

static int	parse_color(t_color *color, char *line)
{
	char **rgb;
    
    rgb = ft_split(line, ',');
	int i  = 0;
	while (rgb[i])
	{
		printf("%s\n", rgb[i]);
		i++;
	}
	if (check_colors(rgb) == 1)
	{
		ft_putstr_fd("Invalid color\n", 2);
		clean_array(rgb);
		return (1);
	}
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
    clean_array(rgb);
	return (0);
}

static int	parse_texture(t_data *data, char *line)
{
	while (*line == ' ')
		line++;
	if (!ft_strncmp(line, "NO ", 3))
		data->n_path = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "SO ", 3))
		data->s_path = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "WE ", 3))
		data->w_path = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "EA ", 3))
		data->e_path = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "F ", 2))
	{
		if (parse_color(&data->floor_color, line + 2) == 1)
			return (1);
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		if (parse_color(&data->ceiling_color, line + 2))
			return (1);
	}
	return (0);
}

static void	find_player(t_data *data)
{
	int	y;

	y = 0;
	while (data->map_data.grid[y])
	{
		int x = 0;
		while (data->map_data.grid[y][x])
		{
			char c = data->map_data.grid[y][x];
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

static void copy_map_grid(t_data *data, int start, int total)
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

int    parse_map(char *map_name, t_data *data)
{
    int fd;
    char *line;
    int i;
    int line_count;
    int map_start;

    i = 0;
    line_count = 0;
    map_start = -1;
    fd = open(map_name, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("Error opening file", 2);
        return (1);
    }
	line = get_next_line(fd);
    while (line)
	{
		data->map[i] = line;
		if (is_map(line) && map_start == -1)
			map_start = i;
		if (map_start == -1)
		{
			if (parse_texture(data, line) == 1)
			{
				free(line);
				close(fd);
				free_first(data);
				return (1);
			}
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
    data->map[i] = NULL;
    close(fd);
    if (map_start >= 0)
		copy_map_grid(data, map_start, i);
	return (0);
}
