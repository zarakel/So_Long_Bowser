/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:41:03 by juan              #+#    #+#             */
/*   Updated: 2021/11/30 15:54:58 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../lib/GNL/get_next_line.h"
#include "../inc/macro.h"
#include "../inc/struct.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char	**malloc_map_arr(char **argv, t_map *n)
{
	int		i;
	char	**ptr;
	char	*tmp;
	int		fd;

	ptr = NULL;
	tmp = NULL;
	i = 0;
	fd = open(argv[1], O_DIRECTORY);
	if (fd != -1)
		error_san(ERRNO10, ERRMSG10);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_san(ERRNO11, ERRMSG11);
	while (get_next_line(fd, &tmp) > 0)
	{
		free(tmp);
		i++;
	}
	ptr = malloc(sizeof(char *) * (i + 1));
	n->max_y = i;
	free(tmp);
	close(fd);
	return (ptr);
}

char	**malloc_and_create_map_string(char **argv, t_map *n)
{
	char	**ptr;
	char	*tmp;
	int		fd;
	int		i;

	ptr = NULL;
	tmp = NULL;
	ptr = malloc_map_arr(argv, n);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || !ptr)
		exit(0);
	i = 0;
	while (get_next_line(fd, &tmp) > 0)
	{
		ptr[i] = ft_gnl_strdup(tmp);
		n->max_x = ft_strlen(ptr[i]);
		free(tmp);
		i++;
	}
	ptr[i] = 0;
	free(tmp);
	close(fd);
	return (ptr);
}
