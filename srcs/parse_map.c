/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:27:43 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/26 17:40:26 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int	parse_color(t_color *color, char *line)
{
	char **rgb;
    
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
		data->map[i] = ft_strdup(line);
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
	if (!is_player_path_correct(&data->map_data, data->map_data.player_x, data->map_data.player_y))
	{
		free_data(data);
		ft_putstr_fd("Error: Map is not closed!\n", 2);
		return (1);
	}
	return (0);
}
