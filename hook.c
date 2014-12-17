/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 11:58:03 by ide-vill          #+#    #+#             */
/*   Updated: 2014/12/17 16:57:39 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			loop_hook(t_all *all)
{
	if (all->img.re)
	{
		ft_bzero(all->img.data, WIN_WIDTH * WIN_HEIGHT * 4);
		ft_draw_map(all);
		mlx_put_image_to_window(all->e.mlx, all->e.win, all->img.img, 0, 0);
		mlx_string_put(all->e.mlx, all->e.win, 10, 40, 0xFFFFFF,
			"Mouse click or 8/5 = Zoom");
		mlx_string_put(all->e.mlx, all->e.win, 10, 60, 0xFFFFFF,
			"Arrows keys = Move");
		mlx_string_put(all->e.mlx, all->e.win, 10, 80, 0xFFFFFF,
			"space bar = reset");
		mlx_string_put(all->e.mlx, all->e.win, 10, 100, 0xFFFFFF,
			"9/6 = rotation");
		mlx_string_put(all->e.mlx, all->e.win, 10, 120, 0xFFFFFF,
			"+/- = altitude");
		all->img.re = 0;
	}
	return (0);
}

int			key_hook(int keycode, t_all *all)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(all->e.mlx, all->img.img);
		exit(0);
	}
	if (keycode == 65451)
		alt_up(&all->img);
	if (keycode == 65453)
		alt_down(&all->img);
	if (keycode == 65465)
		adj_less(&all->img);
	if (keycode == 65462)
		adj_plus(&all->img);
	if (keycode == 65362)
		move_up(all);
	if (keycode == 65364)
		move_down(all);
	if (keycode == 65363)
		move_right(all);
	if (keycode == 65361)
		move_left(all);
	if (keycode == 32)
		ft_init(all);
	if (keycode == 65464)
	{
		all->img.zoom++;
		all->img.re = 1;
	}
	if (keycode == 65461)
	{
		all->img.zoom--;
		all->img.re = 1;
	}
	return (0);
}

int			mouse_hook(int button, int x, int y, t_all *all)
{
	x = x;
	y = y;
	if (button == 4)
	{
		all->img.zoom++;
		all->img.re = 1;
	}
	if (button == 5)
	{
		if (all->img.zoom)
			all->img.zoom--;
		all->img.re = 1;
	}
	return (0);
}

int			expose_hook(t_all *all)
{
	mlx_put_image_to_window(all->e.mlx, all->e.win, all->img.img, 0, 0);
	mlx_string_put(all->e.mlx, all->e.win, 10, 40, 0xFFFFFF,
		"Mouse click or 8/5 = Zoom");
	mlx_string_put(all->e.mlx, all->e.win, 10, 60, 0xFFFFFF,
		"Arrows keys = Move");
	mlx_string_put(all->e.mlx, all->e.win, 10, 80, 0xFFFFFF,
		"space bar = reset");
	mlx_string_put(all->e.mlx, all->e.win, 10, 100, 0xFFFFFF,
		"9/6 = rotation");
	mlx_string_put(all->e.mlx, all->e.win, 10, 120, 0xFFFFFF,
		"+/- = altitude");
	return (0);
}
