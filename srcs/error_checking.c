/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:19:15 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/26 13:20:25 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_with_error(char *msg, char *line, int fd)
{
	ft_putstr_fd(msg, 2);
	if (line)
		free(line);
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
