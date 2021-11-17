#include "../inc/so_long.h"
#include "../lib/GNL/get_next_line.h"
#include "../lib/mlx/mlx.h"
#include "../lib/libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

void	init_struct(t_list *n)
{
	n->total_map = 0;
	n->max_x = 0;
	n->max_y = 0;
	n->P = 0;
	n->C = 0;
	n->E = 0;
}

int	main(int argc, char *argv[])
{
	t_list	n;
	int	i;

	i = 0;
	if (argc != 2)
		error_san(ERRNO0, ERRMSG0);
	init_struct(&n);
	n.total_map = build_map(argv, &n);
	check_bit_by_bit(n.total_map, &n);
	while (n.total_map[i])
	{
		printf("total_map[%d] = %s\n", i, n.total_map[i]);
		i++;
	}
	free_split(n.total_map);
	return (0);
}
