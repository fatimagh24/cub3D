/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasan <rhasan@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:32:45 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/29 12:28:38 by rhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_colors(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		return (1);
	if (check_digit_color(rgb) == 1)
		return (1);
	return (0);
}

int	check_digit_color(char **rgb)
{
	int	i;
	int	j;
	int	val;

	i = 0;
	val = 0;
	while (i < 3)
	{
		j = 0;
		while (rgb[i][j])
		{
			if (rgb[i][j] != ' ' && rgb[i][j] != '\t' && rgb[i][j] != '\n')
			{
				if (!ft_isdigit((rgb[i][j])))
					return (1);
			}
			j++;
		}
		val = ft_atoi(rgb[i]);
		if (val < 0 || val > 255)
			return (1);
		i++;
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
