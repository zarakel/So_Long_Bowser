#include "../inc/so_long.h"
#include "../inc/macro.h"
#include "../lib/libft/libft.h"
#include <unistd.h>

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
	exit(0);
}
