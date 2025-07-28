/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:19:15 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/28 11:06:43 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_with_error(char *msg, char *line, int fd)
{
	(void)line;
	ft_putstr_fd(msg, 2);
	if (fd >= 0)
		close(fd);
	return (1);
}

int	check_line_content(char *line, t_config_state *s, int fd)
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
			return (exit_with_error("Error: Missing or extra configers \n", line, fd));
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
	line = get_next_line(fd);
	while (line)
	{
		if (check_line_content(line, &s, fd) == 1)
		{
			if (line)
			{
				free(line);
				line = NULL;
			}
			close(fd);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (0);
}

int	check_map(char **grid, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (i == 0 || i == map->height - 1 || j == 0 || j == (int)(ft_strlen(grid[i]) - 1))
			{
				while (grid[i][j] == ' ' ||  grid[i][j] == '\t' || grid[i][j] == '\v' || grid[i][j] == '\f' || grid[i][j] == '\r')
					j++;
				if (grid[i][j] != '1' || (grid[i][j] != '1' || grid[i][ft_strlen(grid[i]) - 1] != '1'))
				{
					ft_putstr_fd("ERROR: INVALID WALL\n", 2);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

// static int	exit_with_error(char *msg, char *line, int fd)
// {
// 	ft_putstr_fd(msg, 2);
// 	if (line)
// 	{
// 		free(line);
// 	}
// 	if (fd >= 0)
// 		close(fd);
// 	return (1);
// }

// static int	check_line_content(char *line, t_config_state *s, int fd)
// {
// 	if (line[0] == '\n')
// 		return (0);
// 	else if (ft_strncmp(line, "NO ", 3) == 0)
// 		s->no++;
// 	else if (ft_strncmp(line, "SO ", 3) == 0)
// 		s->so++;
// 	else if (ft_strncmp(line, "WE ", 3) == 0)
// 		s->we++;
// 	else if (ft_strncmp(line, "EA ", 3) == 0)
// 		s->ea++;
// 	else if (ft_strncmp(line, "F ", 2) == 0)
// 		s->f++;
// 	else if (ft_strncmp(line, "C ", 2) == 0)
// 		s->c++;
// 	else if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
// 	{
// 		if (s->no != 1 || s->so != 1 || s->we != 1 || s->ea != 1
// 			|| s->f != 1 || s->c != 1)
// 			return (exit_with_error("Error: Missing configers \n", line, fd));
// 		s->config_done = 1;
// 	}
// 	else if (!s->config_done)
// 		return (exit_with_error("Error: Invalid line before map section\n", line, fd));
// 	return (0);
// }

// int	check_valid_map(char *map_name)
// {
// 	int				fd;
// 	char			*line;
// 	t_config_state	s;

// 	s.no = 0;
// 	s.so = 0;
// 	s.we = 0;
// 	s.ea = 0;
// 	s.f = 0;
// 	s.c = 0;
// 	s.config_done = 0;
// 	fd = open(map_name, O_RDONLY);
// 	if (fd < 0)
// 		return (exit_with_error("Error opening map file\n", NULL, -1));
// 	while ((line = get_next_line(fd)))
// 	{
// 		if (check_line_content(line, &s, fd) == 1)
// 		{
// 			free(line);
// 			close(fd);
// 			return (1);
// 		}
// 		free(line);
// 	}
// 	close(fd);
// 	if (s.no != 1 || s.so != 1 || s.we != 1 || s.ea != 1 || s.f != 1 || s.c != 1)
// 		return (exit_with_error("Error: Missing or duplicate configuration lines\n", line, -1));
// 	return (0);
// }

// void	fix_map(char **temp)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (temp[i])
// 	{
// 		j = 0;
// 		while (temp[i][j])
// 		{
// 			if (temp[i][j] == '\n')
// 				temp[i][j] = '\0';
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	check_map(char **grid, t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (grid[i])
// 	{
// 		j = 0;
// 		while (grid[i][j])
// 		{
// 			if (i == 0 || i == map->height - 1 || j == 0 || j == ft_strlen(grid[i]) - 1)
// 			{
// 				while (grid[i][j] == ' ' ||  grid[i][j] == '\t' || grid[i][j] == '\v' || grid[i][j] == '\f' || grid[i][j] == '\r')
// 					j++;
// 				if (grid[i][j] != '1' || (grid[i][j] != '1' || grid[i][ft_strlen(grid[i]) - 1] != '1'))
// 				{
// 					ft_putstr_fd("ERROR: INVALID WALL\n", 2);
// 					return (1);
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// static int	is_digit_str(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!s || !*s)
// 		return 0;
// 	while (s[i])
// 	{
// 		if (ft_isdigit(s[i]) == 0)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	check_colors(char **rgb)
// {
// 	int	i;
// 	int	val;

// 	i = 0;
// 	while (rgb[i])
// 		i++;
// 	if (i != 3)
// 		return (1);
// 	i = 0;
// 	while (i < 3)
// 	{
// 		while (*rgb[i] == ' ' || *rgb[i] == '\t')
// 			rgb[i]++;
// 		if (is_digit_str(rgb[i]))
// 			return (1);
// 		val = ft_atoi(rgb[i]);
// 		if (val < 0 || val > 255)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }


// int	has_single_player(char **map)
// {
// 	int	i;
// 	int	j;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == 'N' || map[i][j] == 'S' ||
// 				map[i][j] == 'E' || map[i][j] == 'W')
// 				count++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (count != 1)
// 	{
// 		ft_putstr_fd("Error: Invalid number of players\n", 2);
// 		return (1);
// 	}
// 	return (0);
// }