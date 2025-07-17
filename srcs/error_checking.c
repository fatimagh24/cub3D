/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:19:15 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/17 16:44:39 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	exit_with_error(char *msg, char *line, int fd)
{
	write(2, msg, ft_strlen(msg));
	if (line)
		free(line);
	if (fd >= 0)
		close(fd);
	exit(EXIT_FAILURE);
}

static void	check_line_content(char *line, t_config_state *s, int fd)
{
	if (line[0] == '\n')
		return ;
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
			exit_with_error("Error: Map appeared before config complete\n", line, fd);
		s->config_done = 1;
	}
	else if (!s->config_done)
		exit_with_error("Error: Invalid line before map section\n", line, fd);
}

void	check_valid_map(char *map_name)
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
		exit_with_error("Error opening map file\n", NULL, -1);
	while ((line = get_next_line(fd)))
	{
		check_line_content(line, &s, fd);
		free(line);
	}
	close(fd);
	if (s.no != 1 || s.so != 1 || s.we != 1 || s.ea != 1 || s.f != 1 || s.c != 1)
		exit_with_error("Error: Missing or duplicate configuration lines\n", NULL, -1);
}

void check_map(char **grid, t_map *map)
{
	int i = 0;
	while (grid[i])
	{
		int j = 0;
		while (grid[i][j])
		{
			if (i == 0 && (grid[i][j] == 'N' || grid[i][j] == 'S' ||
				grid[i][j] == 'E' || grid[i][j] == 'W'))
			{
				printf("Error: PLAYER CANNOT BE ON THE EDGE OF THE MAP\n");
				exit(EXIT_FAILURE);
			}
			if ((i == 0 || (i == map->height - 1)) && (grid[i][j] == '0'))
			{
				printf("Error: WALL IS BROKEN\n");
				exit(EXIT_FAILURE);
			}
			if (grid[i][j] == 'N' || grid[i][j] == 'S' ||
				grid[i][j] == 'E' || grid[i][j] == 'W')
			{
				if (grid[i + 1] && grid[i + 1][j] != '1' &&
					grid[i - 1] && grid[i - 1][j] != '1' &&
					grid[i][j + 1] != '1' && grid[i][j - 1] != '1')
				{
					write(2, "Error: Player not surrounded by walls\n", 39);
					exit(EXIT_FAILURE);
				}
			}
            if ()
			j++;
		}
		i++;
	}
}
