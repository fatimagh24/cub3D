/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:47:09 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/26 13:21:45 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int    main(int argc, char **argv)
{
    t_data data;
    t_map   map;

	if (argc != 2)
	{
		write(2, "Usage: ./cub3d map.cub\n", 24);
		return (1);
	}
	if (ft_strlen(argv[1]) < 4 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
	{
		write(2, "Error: Map file must have a .cub extension\n", 43);
		return (1);
	}
	if (check_valid_map(argv[1]) == 1)
		return (1);
    init_map(&map);
    init_data(&data, &map);
    if (parse_map(argv[1], &data) == 1)
		return (1);
	free_data(&data);
	return (0);

}

