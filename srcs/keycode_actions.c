/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:46:22 by juan              #+#    #+#             */
/*   Updated: 2021/11/30 17:36:49 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/struct.h"
#include "../inc/keycode_qwerty.h"
#include "../inc/macro.h"
#include "../lib/GNL/get_next_line.h"
#include "../lib/libft/libft.h"
#include <stdio.h>
#include <mlx.h>

void	keycode_esc(t_map *map)
{
	mlx_destroy_window(map->vars.mlx, map->vars.win);
	map->vars.win = 0;
	write(1, "ESC have been used\n", 20);
	exit(0);
}

void	keycode_up(t_map *map, int old_p_y)
{
	if (map->total_map[map->p_y - 1][map->p_x] == '0'
		|| map->total_map[map->p_y - 1][map->p_x] == 'C')
	{
		old_p_y = map->p_y;
		print_moves(map);
		if (map->total_map[map->p_y - 1][map->p_x] == 'C')
			map->c--;
		map->p_y--;
		map->total_map[map->p_y][map->p_x] = 'P';
		map->total_map[old_p_y][map->p_x] = '0';
	}
	else if (map->total_map[map->p_y - 1][map->p_x] == 'E'
		&& map->c == 0)
	{
		old_p_y = map->p_y;
		print_moves(map);
		map->p_y--;
		map->total_map[map->p_y][map->p_x] = 'P';
		map->total_map[old_p_y][map->p_x] = '0';
		mlx_destroy_window(map->vars.mlx, map->vars.win);
		map->vars.win = 0;
		write(1, "Level Completed !\n", 19);
		exit(0);
	}
}

void	keycode_down(t_map *map, int old_p_y)
{
	if (map->total_map[map->p_y + 1][map->p_x] == '0'
		|| map->total_map[map->p_y + 1][map->p_x] == 'C')
	{
		old_p_y = map->p_y;
		print_moves(map);
		if (map->total_map[map->p_y + 1][map->p_x] == 'C')
			map->c--;
		map->p_y++;
		map->total_map[map->p_y][map->p_x] = 'P';
		map->total_map[old_p_y][map->p_x] = '0';
	}
	else if (map->total_map[map->p_y + 1][map->p_x] == 'E'
		&& map->c == 0)
	{
		old_p_y = map->p_y;
		print_moves(map);
		map->p_y++;
		map->total_map[map->p_y][map->p_x] = 'P';
		map->total_map[old_p_y][map->p_x] = '0';
		mlx_destroy_window(map->vars.mlx, map->vars.win);
		map->vars.win = 0;
		write(1, "Level Completed !\n", 19);
		exit(0);
	}
}

void	keycode_left(t_map *map, int old_p_x)
{
	if (map->total_map[map->p_y][map->p_x - 1] == '0'
		|| map->total_map[map->p_y][map->p_x - 1] == 'C')
	{
		old_p_x = map->p_x;
		print_moves(map);
		if (map->total_map[map->p_y][map->p_x - 1] == 'C')
			map->c--;
		map->p_x--;
		map->total_map[map->p_y][map->p_x] = 'P';
		map->total_map[map->p_y][old_p_x] = '0';
	}
	else if (map->total_map[map->p_y][map->p_x - 1] == 'E'
		&& map->c == 0)
	{
		old_p_x = map->p_x;
		print_moves(map);
		map->p_x--;
		map->total_map[map->p_y][map->p_x] = 'P';
		map->total_map[map->p_y][old_p_x] = '0';
		mlx_destroy_window(map->vars.mlx, map->vars.win);
		map->vars.win = 0;
		write(1, "Level Completed !\n", 19);
		exit(0);
	}
}

void	keycode_right(t_map *map, int old_p_x)
{
	if (map->total_map[map->p_y][map->p_x + 1] == '0'
		|| map->total_map[map->p_y][map->p_x + 1] == 'C')
	{
		old_p_x = map->p_x;
		print_moves(map);
		if (map->total_map[map->p_y][map->p_x + 1] == 'C')
			map->c--;
		map->p_x++;
		map->total_map[map->p_y][map->p_x] = 'P';
		map->total_map[map->p_y][old_p_x] = '0';
	}
	else if (map->total_map[map->p_y][map->p_x + 1] == 'E'
		&& map->c == 0)
	{
		old_p_x = map->p_x;
		print_moves(map);
		map->p_x--;
		map->total_map[map->p_y][map->p_x] = 'P';
		map->total_map[map->p_y][old_p_x] = '0';
		mlx_destroy_window(map->vars.mlx, map->vars.win);
		map->vars.win = 0;
		write(1, "Level Completed !\n", 19);
		exit(0);
	}
}
