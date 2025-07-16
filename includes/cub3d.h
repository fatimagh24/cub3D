/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:51:41 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/16 12:49:54 by fghanem          ###   ########.fr       */
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

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     width;
    int     height;
    char    **map;
    int     player_x;
    int     player_y;
    double  player_dir;
    char    *e_path; //east texture
    char    *n_path; //north texture
    char    *s_path; //south texture
    char    *w_path;  //west texture
    t_map   map_data;
    t_color floor_color;
    t_color ceiling_color;
}   t_data;

void    parse_map(char *map_name, t_data *data);
void init_data(t_data *data, t_map *map);
void    init_map(t_map *map);

#endif