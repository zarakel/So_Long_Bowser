/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ciao.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:23:54 by juan              #+#    #+#             */
/*   Updated: 2021/11/24 18:23:56 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx/mlx.h"
#include "../inc/so_long.h"
#include <stdlib.h>
#include <unistd.h>

int	ciao(t_map *map)
{
	mlx_destroy_window(map->vars.mlx, map->vars.win);
	map->vars.win = 0;
	free_split(map->total_map);
	write(1, "Ciao !\n", 9);
	exit(0);
}
