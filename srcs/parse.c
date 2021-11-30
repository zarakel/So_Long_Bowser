/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <jbuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:43:00 by juan              #+#    #+#             */
/*   Updated: 2021/11/30 18:09:24 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"	
#include "../inc/struct.h"	
#include "../inc/macro.h"	
#include "../lib/GNL/get_next_line.h"
#include "../lib/libft/libft.h"
#include <stdio.h>

char	**build_map(char **argv, t_map *n)
{
	char	**tmp;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(argv[1]);
	tmp = NULL;
	if (size >= 4)
	{
		if (!ft_strnstr(argv[1] + size - 4, ".ber", 4))
			error_san(ERREXT, ERRMSG6);
		tmp = malloc_and_create_map_string(argv, n);
	}
	return (tmp);
}

void	check_bit_by_bit(char **total_map, t_map *n)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (n->max_y < 2)
		end(n->total_map, ERRNO1, ERRMSG1);
	while (total_map[y])
	{
		if ((int)ft_strlen(total_map[y]) != n->max_x)
			end(n->total_map, ERRNO2, ERRMSG2);
		check_requirements(total_map[y], y, n);
		y++;
	}
	if (n->p < 1 || n->c < 1 || n->e < 1)
		end(n->total_map, ERRNO5, ERRMSG5);
}

void	check_requirements(char *line_map, int y, t_map *n)
{
	int	x;

	x = 0;
	while (line_map[x])
	{
		if (y == 0 || y == n->max_y - 1)
		{
			if (line_map[x] != '1')
				end(n->total_map, ERRNO3, ERRMSG3);
		}
		else
			elements_signal(line_map[x], x, y, n);
		x++;
	}
}

int	elements_signal(char char_map, int x, int y, t_map *n)
{
	if (char_map != '1' && char_map != '0' && char_map != 'E'
		&& char_map != 'C' && char_map != 'P')
		end(n->total_map, ERRNO12, ERRMSG12);
	if (x == 0 || x == n->max_x - 1)
	{
		if (char_map != '1')
			end(n->total_map, ERRNO4, ERRMSG4);
	}
	if (char_map == 'P')
	{
		n->p++;
		n->p_x = x;
		n->p_y = y;
		if (n->p > 1)
			end(n->total_map, ERRNO7, ERRMSG7);
	}
	if (char_map == 'C')
		n->c++;
	if (char_map == 'E')
		n->e++;
	return (0);
}
