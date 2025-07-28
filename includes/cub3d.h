/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:51:41 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/28 10:06:14 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
#include <X11/keysym.h>

#define MOUSE_SENSITIVITY 0.002

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
    int     width;
    int     player_x;
    int     player_y;
    char    player_dir;
    int     height;
}   t_map;

typedef struct s_texture
{
    void    *img;
    char    *addr;
    int     width;
    int     height;
    int     bpp;
    int     line_len;
    int     endian;
} t_texture;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     width;
    int     height;
    void    *img_ptr;
    char    *img_data;
    int     bpp;
    int     line_len;
    int     endian;
    char    **map;
    double  pos_x;
    double  pos_y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
    int     player_x;
    int     player_y;
    double  player_dir;
    char    *e_path;
    char    *n_path;
    char    *s_path;
    char    *w_path;
    int last_mouse_x;
    int mouse_captured;
    t_texture north;
    t_texture south;
    t_texture east;
    t_texture west;
    t_map   map_data;
    t_color floor_color;
    t_color ceiling_color;

} t_data;

int close_window(void *param);
int key_press(int keycode, void *param);
void init_window(t_data *game, char *map_file);
void init_player(t_data *data);
int render_frame(t_data *data);
void load_texture(t_data *data, t_texture *tex, char *path);
//void free_all(t_data *data);
int    parse_map(char *map_name, t_data *data);
void init_data(t_data *data, t_map *map);
void    init_map(t_map *map);
int	check_valid_map(char *map_name);
// void	check_valid_map(const char *map_name);
int     check_map(char **grid, t_map *map);
void    clean_array(char **arr);
//void	free_data(t_data *data);
int	has_single_player(char **map);
void move_left(t_data *data, double speed);
void move_right(t_data *data, double speed);
void move_backward(t_data *data, double speed);
void move_forward(t_data *data, double speed);
void rotate_player(t_data *player, double angle);
int	mouse_move(int x, int y, void *param);
//void	free_first(t_data *data);
void	fix_map(char **temp);
int	check_colors(char **rgb);
//void	free_map(t_map *map);
int check_digit_color(char **rgb);
void	find_player(t_data *data);
int	is_map(const char *line);
void copy_map_grid(t_data *data, int start, int total);
int	flood_fill(char **grid, int x, int y, int height);
int	is_player_path_correct(t_map *map, int px, int py);
char	**copy_grid(char **grid, int height);
void	free_grid(char **grid);
void free_textures(t_data *data);
//int clean_exit(t_data *data, char *error_msg, int code);
void	destroy_game(t_data *data);
#endif
