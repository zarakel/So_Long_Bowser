/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:45:32 by juan              #+#    #+#             */
/*   Updated: 2021/11/24 18:46:13 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/macro.h"
#include "../lib/libft/libft.h"
#include <unistd.h>
#include <stdio.h>

void	free_split(char **cpy_argv)
{
	char	**tmp;

	tmp = cpy_argv;
	while (*tmp)
		free(*tmp++);
	free(cpy_argv);
}

void	error_san(int error, char *error_msg)
{
	if (error == ERREXT)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO1)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO2)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO3)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO4)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO5)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO7)
		write(2, error_msg, ft_strlen(error_msg));
	exit(0);
}

void	print_moves(t_map *map)
{
	map->moves++;
	ft_putstr_fd("Moves : ", 1);
	ft_putnbr_fd(map->moves, 1);
	ft_putstr_fd(" \n", 1);
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->total_map[i])
	{
		printf("total_map[%d] = %s\n", i, map->total_map[i]);
		i++;
	}
}
