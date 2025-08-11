/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:32:45 by fghanem           #+#    #+#             */
/*   Updated: 2025/08/11 13:10:26 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

static	int	check_str_color(char *c)
{
	int	j;
	int	has_digit;

	j = 0;
	has_digit = 0;
	while (c[j])
	{
		if (c[j] != ' ' && c[j] != '\t' && c[j] != '\n')
		{
			if (!ft_isdigit((c[j])))
				return (1);
			has_digit = 1;
		}
		j++;
	}
	return (has_digit);
}

int	check_digit_color(char **rgb)
{
	int	i;
	int	j;
	int	val;
	int	has_digit;

	i = 0;
	val = 0;
	while (i < 3)
	{
		if (!rgb[i])
			return (1);
		j = 0;
		has_digit = 0;
		has_digit = check_str_color(rgb[i]);
		if (!has_digit)
			return (1);
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
		ft_putstr_fd("Error:Invalid map: incorrect number of "
			"players or invalid characters\n", 2);
		return (1);
	}
	return (0);
}

int	map_not_last(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n' && map[i][j + 1] == '\0' && !map[i + 1])
			{
				ft_putstr_fd("Error: invalid extra lines after map\n", 2);
				return (1);
			}
			else
				j++;
		}
		i++;
	}
	return (0);
}
