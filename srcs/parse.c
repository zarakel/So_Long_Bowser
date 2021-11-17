#include "../inc/so_long.h"	
#include "../lib/GNL/get_next_line.h"
#include "../lib/mlx/mlx.h"
#include "../lib/libft/libft.h"
#include <fcntl.h>

char	**build_map(char **argv, t_list *n)
{
	char	**tmp;
	int	size;

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

void	check_bit_by_bit(char **total_map, t_list *n)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	n->max_x = ft_strlen(total_map[x]);
	if (n->max_y < 2)
	{
		free_split(n->total_map);
		error_san(ERRNO1, ERRMSG1);
	}
	while (total_map[y])
	{
		check_requirements(total_map[y], y, n);
		y++;
	}
	if (n->P < 1 || n->C < 1 || n->E < 1)
	{
		free_split(n->total_map);
		error_san(ERRNO5, ERRMSG5);
	}
	return ;
}


void	check_requirements(char *line_map, int y, t_list *n)
{
	int	x;

	x = 0;
	while (line_map[x])
	{	
		if ((int)ft_strlen(line_map) != n->max_x)
		{
			free_split(n->total_map);
			error_san(ERRNO2, ERRMSG2);
		}
		if (y == 0 || y == n->max_y) 
		{
			if (line_map[x] != '1')
			{
				free_split(n->total_map);
				error_san(ERRNO3, ERRMSG3);
			}
		}
		
		else 
			elements_signal(line_map[x], x, n);
		x++;
	}
}


int	elements_signal(char char_map, int x, t_list *n)
{
	if (x == 0 || x == n->max_x)
	{
		if (char_map != '1')
		{
			free_split(n->total_map);
			error_san(ERRNO4, ERRMSG4);
		}
	}	
	if (char_map == 'P')
		n->P++;
	if (char_map == 'C')
		n->C++;
	if (char_map == 'E')
		n->E++;
	return (0);
}
