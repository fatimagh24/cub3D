/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:51:41 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/26 17:35:23 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>
// # include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_config_state
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
	int	config_done;
    int player_found;
}	t_config_state;

typedef struct s_color
{
    int r;
    int g;
    int b;
}   t_color;

typedef struct s_map
{
    char    **grid;
    int     player_x;
    int     player_y;
    char    player_dir;
    int     height;
}   t_map;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     height;
    char    **map;
    double  player_dir;
    char    *e_path; //east texture
    char    *n_path; //north texture
    char    *s_path; //south texture
    char    *w_path;  //west texture
    t_map   map_data;
    t_color floor_color;
    t_color ceiling_color;
}   t_data;

int    parse_map(char *map_name, t_data *data);
void init_data(t_data *data, t_map *map);
void    init_map(t_map *map);
int	check_valid_map(char *map_name);
// void	check_valid_map(const char *map_name);
int     check_map(char **grid, t_map *map);
void    clean_array(char **arr);
void	free_data(t_data *data);
void	fix_map(char **temp);
int	check_colors(char **rgb);
int	has_single_player(char **map);
void	free_first(t_data *data);
void copy_map_grid(t_data *data, int start, int total);
int	is_map(const char *line);
int	parse_color(t_color *color, char *line);
int	parse_texture(t_data *data, char *line);
int check_digit_color(char **rgb);
int	check_line_content(char *line, t_config_state *s, int fd);
int	exit_with_error(char *msg, char *line, int fd);
void	find_player(t_data *data);
void	free_grid(char **grid);
char	**copy_grid(char **grid, int height);
int	is_player_path_correct(t_map *map, int px, int py);
int	flood_fill(int x, int y, char **grid, int height);
void	free_map(t_map *map);




#endif