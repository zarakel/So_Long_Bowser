/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:36:43 by juan              #+#    #+#             */
/*   Updated: 2021/11/24 18:56:53 by juan             ###   ########.fr       */
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

void	init_struct(t_map *map)
{
	map->total_map = 0;
	map->max_x = 0;
	map->max_y = 0;
	map->moves = 0;
	map->p = 0;
	map->p_x = 0;
	map->p_y = 0;
	map->c = 0;
	map->e = 0;
}

int	main(int argc, char *argv[])
{
	t_map	map;
	int		i;

	i = 0;
	if (argc != 2)
		error_san(ERRNO0, ERRMSG0);
	init_struct(&map);
	map.total_map = build_map(argv, &map);
	check_bit_by_bit(map.total_map, &map);
	cast_img(map);
	free_split(map.total_map);
	return (0);
}
