/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:20:06 by juan              #+#    #+#             */
/*   Updated: 2021/11/25 14:33:40 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/struct.h"
#include "../inc/keycode_qwerty.h"
#include "../inc/macro.h"
#include "../lib/GNL/get_next_line.h"
#include "../lib/mlx/mlx.h"
#include "../lib/libft/libft.h"
#include <stdio.h>

void	print(t_map *map)
{
	int	x;
	int	y;

	mlx_clear_window(map->vars.mlx, map->vars.win);
	map->img.img = mlx_new_image(map->vars.mlx, map->win_w, map->win_h);
	map->img.addr = mlx_get_data_addr(map->img.img,
			&map->img.bits_per_pixel, &map->img.line_length,
			&map->img.endian);
	x = -1;
	while (++x < map->max_x)
	{
		y = -1;
		while (++y < map->max_y)
		{
			tiles(map, x, y);
		}
	}
	mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->img.img, 0, 0);
	mlx_destroy_image(map->vars.mlx, map->img.img);
}

void	tiles(t_map *map, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < PIXEL)
	{
		j = -1;
		while (++j < PIXEL)
		{
			pixel(map, (i + x * PIXEL), (j + y * PIXEL),
				color(map, x, y));
		}
	}
}

void	pixel(t_map *map, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x <= map->win_w && y <= map->win_h))
	{
		dst = map->img.addr + (y * map->img.line_length + x
				* (map->img.bits_per_pixel / 8));
		*(int *) dst = color;
	}
}

int	color(t_map *map, int x, int y)
{
	if (map->total_map[y][x] == '0')
		return (0x00ACAB0);
	else if (map->total_map[y][x] == 'P')
		return (0x000BACA0);
	else if (map->total_map[y][x] == '1')
		return (0x00000ABA);
	else if (map->total_map[y][x] == 'E')
		return (0x00CADABA);
	else
		return (0x0000BFF0);
}
