/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:51:41 by fghanem           #+#    #+#             */
/*   Updated: 2025/08/10 17:24:19 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>

# define MOUSE_SENSITIVITY 0.002
# define TILE_SIZE 64

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			line_len;
	int			endian;
}				t_texture;

typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
	t_texture	*tex;
}				t_ray;

typedef struct s_config_state
{
	int			no;
	int			so;
	int			we;
	int			ea;
	int			f;
	int			c;
	int			config_done;
	int			player_found;
}				t_config_state;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			player_x;
	int			player_y;
	char		player_dir;
	int			height;
}				t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			line_len;
	int			endian;
	char		**map;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			player_x;
	int			player_y;
	double		player_dir;
	char		*e_path;
	char		*n_path;
	char		*s_path;
	char		*w_path;
	int			last_mouse_x;
	int			mouse_captured;
	int move_forward;
    int move_backward;
    int move_left;
    int move_right;
    int rotate_left;
    int rotate_right;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_map		map_data;
	t_color		floor_color;
	t_color		ceiling_color;

}				t_data;

int				close_window(void *param);
int				render_frame(t_data *data);
int				parse_map(char *map_name, t_data *data);
int				check_valid_map(char *map_name);
int				check_map(char **grid, t_map *map);
int				has_single_player(char **map);
int				mouse_move(int x, int y, void *param);
int				check_colors(char **rgb);
int				check_digit_color(char **rgb);
int				is_map(const char *line);
int				copy_map_grid(t_data *data, int start, int total);
int				flood_fill(char **grid, int x, int y, int height);
int				is_player_path_correct(t_map *map, int px, int py);
int				is_walkable(t_data *data, double x, double y);
int				key_press(int keycode, void *param);
int				check_map_content(char **grid, int i);
int key_release(int keycode, void *param);
int				map_not_last(char **map);
char			**copy_grid(char **grid, int height);
void			free_grid(char **grid);
void			free_textures(t_data *data);
void			destroy_game(t_data *data);
void			calc_line_dimensions(t_data *data, t_ray *ray);
void			calc_tex_x(t_data *data, t_ray *ray);
void			choose_texture(t_data *data, t_ray *ray);
void			draw_vertical_line(t_data *data, t_ray *ray, int x);
void			raycasting(t_data *data);
void			put_pixel(t_data *data, int x, int y, int color);
void			destroy_game_first(t_data *data);
void			find_player(t_data *data);
void			fix_map(char **temp);
void			move_left(t_data *data, double speed);
void			move_right(t_data *data, double speed);
void			move_backward(t_data *data, double speed);
void			move_forward(t_data *data, double speed);
void			rotate_player(t_data *player, double angle);
void			init_data(t_data *data, t_map *map);
void			init_map(t_map *map);
void			clean_array(char **arr);
void			init_window(t_data *game, char *map_file);
void			init_player(t_data *data);

#endif
