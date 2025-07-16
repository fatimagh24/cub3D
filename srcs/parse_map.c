/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:27:43 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/16 14:10:23 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_data(t_data *data, t_map *map)
{
    data->mlx_ptr = NULL;
    data->win_ptr = NULL;
    data->width = 0;
    data->height = 0;
    data->map = NULL;
    data->map = malloc(sizeof(char *) * 100);
    if (!data->map)
        perror("Memory allocation failed");
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
    map->grid = NULL;
    map->width = 0;
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

static void	parse_color(t_color *color, char *line)
{
	char **rgb;
    
    rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		return;
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
    // free_array(rgb);
}

static void	parse_texture(t_data *data, char *line)
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
		parse_color(&data->floor_color, line + 2);
	else if (!ft_strncmp(line, "C ", 2))
		parse_color(&data->ceiling_color, line + 2);
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
		int len = ft_strlen(data->map[start]);
		if (len > data->map_data.width)
			data->map_data.width = len;
		start++;
		i++;
	}
	data->map_data.grid[i] = NULL;
	data->map_data.height = i;
	find_player(data);
}

void    parse_map(char *map_name, t_data *data)
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
        perror("Error opening file");
        return;
    }
    while ((line = get_next_line(fd)))
	{
		data->map[i] = ft_strdup(line);
		if (is_map(line) && map_start == -1)
			map_start = i;
		if (map_start == -1)
			parse_texture(data, line);
		free(line);
		i++;
	}
    data->map[i] = NULL;
    close(fd);
    if (map_start >= 0)
		copy_map_grid(data, map_start, i);
}

