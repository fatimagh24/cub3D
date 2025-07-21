/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:19:15 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/21 16:19:35 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	exit_with_error(char *msg, char *line, int fd)
{
	ft_putstr_fd(msg, 2);
	if (line)
	{
		free(line);
	}
	if (fd >= 0)
		close(fd);
	return (1);
}

static int	check_line_content(char *line, t_config_state *s, int fd)
{
	if (line[0] == '\n')
		return (0);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		s->no++;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		s->so++;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		s->we++;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		s->ea++;
	else if (ft_strncmp(line, "F ", 2) == 0)
		s->f++;
	else if (ft_strncmp(line, "C ", 2) == 0)
		s->c++;
	else if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
	{
		if (s->no != 1 || s->so != 1 || s->we != 1 || s->ea != 1
			|| s->f != 1 || s->c != 1)
			return (exit_with_error("Error: Missing configers \n", line, fd));
		s->config_done = 1;
	}
	else if (!s->config_done)
		return (exit_with_error("Error: Invalid line before map section\n", line, fd));
	return (0);
}

int	check_valid_map(char *map_name)
{
	int				fd;
	char			*line;
	t_config_state	s;

	s.no = 0;
	s.so = 0;
	s.we = 0;
	s.ea = 0;
	s.f = 0;
	s.c = 0;
	s.config_done = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (exit_with_error("Error opening map file\n", NULL, -1));
	while ((line = get_next_line(fd)))
	{
		if (check_line_content(line, &s, fd) == 1)
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
	}
	close(fd);
	if (s.no != 1 || s.so != 1 || s.we != 1 || s.ea != 1 || s.f != 1 || s.c != 1)
		return (exit_with_error("Error: Missing or duplicate configuration lines\n", line, -1));
	return (0);
}

static int	check_top_bottom_walls(char **grid, t_map *map)
{
	int	j;

	j = 0;
	// printf("first line %s\n", grid[0]);
	while (grid[0][j] == ' ')
		j++;
	while (grid[0][j])
	{
		// if (grid[0][j] != '1' && grid[0][j] != ' ' && grid[0][j] != '\n')
		// 	return (ft_putstr_fd("ERROR: INVALID TOP WALL\n", 2), 1);
		j++;
	}
	j = 0;
	while (grid[map->height - 1][j] == ' ')
		j++;
	while (grid[map->height - 1][j])
	{
		// if (grid[map->height - 1][j] != '1' && grid[map->height - 1][j] != ' ')
		// 	return (ft_putstr_fd("ERROR: INVALID BOTTOM WALL\n", 2), 1);
		j++;
	}
	return (0);
}

static int	check_side_walls(char **grid, t_map *map)
{
	int	i;
	int	len;

	i = 0;
	while (i < map->height)
	{
		len = ft_strlen(grid[i]);
		// if ((grid[i][0] != '1' && grid[i][0] != ' ') ||
		// 	(grid[i][len - 1] != '1' && grid[i][len - 1] != ' ')  && grid[i][0] != '\n')
		// 	return (ft_putstr_fd("ERROR: INVALID SIDE WALL\n", 2), 1);
		i++;
	}
	return (0);
}


int	check_map(char **grid, t_map *map)
{
	if (check_top_bottom_walls(grid, map) == 1)
	{
		// ft_putstr_fd("ERROR: INVALID MAP\n", 2);
		return (1);
	}
	if (check_side_walls(grid, map) == 1)
	{
		// ft_putstr_fd("ERROR: INVALID MAP\n", 2);
		return(1);
	}
	return (0);
}

int	has_single_player(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		ft_putstr_fd("Error: Invalid number of players\n", 2);
		return (1);
	}
	return (0);
}
