/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:56:57 by ide-vill          #+#    #+#             */
/*   Updated: 2014/12/16 10:56:59 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int argc)
{
	if (argc != 2)
	{
		ft_putendl_fd("Error.", 2);
		exit(0);
	}
}

void	ft_error_fd(int fd)
{
	if (fd == -1)
	{
		ft_putendl_fd("Does not exist or is invalid.", 2);
		exit(0);
	}
}

void		ft_init (t_all *all)
{
	all->img.alt = 1;
}

int			main(int argc, char **argv)
{
	t_all	all;
	int 	fd;


	ft_error(argc);
	fd = open(argv[1], 'r');
	ft_error_fd(fd);

	all.e.mlx = mlx_init();
	all.e.win = mlx_new_window(all.e.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	all.map.max = 1;
	all.map.min = 0;
	
	//ft_init(all);

	read_map(&all, fd);
	all.img.img = mlx_new_image(all.e.mlx, WIN_WIDTH, WIN_HEIGHT);
	all.img.data = mlx_get_data_addr(all.img.img, &all.img.bpp, &all.img.size_line, &all.img.endian);
	mlx_key_hook(all.e.win, key_hook, &all);
	mlx_mouse_hook(all.e.win, mouse_hook, &all);
	mlx_loop_hook(all.e.mlx, loop_hook, &all);
	mlx_expose_hook(all.e.win, expose_hook, &all);

	printf("ALIVE13\n");
	mlx_loop(all.e.mlx);

	printf("ALIVE14\n");
	return (0);
}