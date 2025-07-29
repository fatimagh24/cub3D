/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:27:43 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/29 12:36:12 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_color(t_color *color, char *line)
{
	char	**rgb;

	rgb = ft_split(line, ',');
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

int	parse_texture(t_data *data, char *line)
{
	while (*line == ' ')
		line++;
	if (!ft_strncmp(line, "NO ", 3))
		data->n_path = ft_strtrim(line + 3, " \n");
	else if (!ft_strncmp(line, "SO ", 3))
		data->s_path = ft_strtrim(line + 3, " \n");
	else if (!ft_strncmp(line, "WE ", 3))
		data->w_path = ft_strtrim(line + 3, " \n");
	else if (!ft_strncmp(line, "EA ", 3))
		data->e_path = ft_strtrim(line + 3, " \n");
	else if (!ft_strncmp(line, "F ", 2))
	{
		if (parse_color(&data->floor_color, line + 2) == 1)
			return (2);
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		if (parse_color(&data->ceiling_color, line + 2))
			return (2);
	}
	return (0);
}

static int	load_map_lines(int fd, t_data *data, int *map_start, int *i)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		data->map[*i] = ft_strdup(line);
		if (is_map(line) && *map_start == -1)
			*map_start = *i;
		if (*map_start == -1 && parse_texture(data, line) == 2)
		{
			free(line);
			free(data->map[*i]);
			data->map[*i] = NULL;
			return (2);
		}
		free(line);
		line = get_next_line(fd);
		(*i)++;
	}
	data->map[*i] = NULL;
	return (0);
}

static int	validate_map_data(t_data *data, int map_start, int line_count)
{
	if (copy_map_grid(data, map_start, line_count))
		return (1);
	if (!is_player_path_correct(&data->map_data,
			data->map_data.player_x, data->map_data.player_y))
	{
		ft_putstr_fd("Error: Player has invalid path!\n", 2);
		return (1);
	}
	return (0);
}

int	parse_map(char *map_name, t_data *data)
{
	int	fd;
	int	i;
	int	map_start;
	int	result;

	i = 0;
	map_start = -1;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error opening file\n", 2);
		return (1);
	}
	result = load_map_lines(fd, data, &map_start, &i);
	close(fd);
	if (result != 0)
		return (result);
	if (map_start < 0)
	{
		ft_putstr_fd("Error: No map found in the file\n", 2);
		return (1);
	}
	return (validate_map_data(data, map_start, i));
}
