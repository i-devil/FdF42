/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 11:58:03 by ide-vill          #+#    #+#             */
/*   Updated: 2014/12/16 11:58:05 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	loop_hook(t_all *all)
{
	ft_bzero(all->img.data, WIN_WIDTH * WIN_HEIGHT * 4);
	ft_draw_map(all);
	mlx_put_image_to_window(all->e.mlx, all->e.win, all->img.img, 0, 0);
	return (0);
}

int			key_hook(int keycode, t_all *all)
{
	(void)all;
	printf("Key: %d\n", keycode);
	if (keycode == 65307)
		exit (0);
	if (keycode == 65451)
		alt_up(&all->img);
	if (keycode == 65453)
		alt_down(&all->img);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_all *all)
{
	(void)all;
	printf("Mouse: %d (%d:%d)\n", button, x, y);
	return (0);
}

int			expose_hook(t_all *all)
{
	mlx_put_image_to_window(all->e.mlx, all->e.win, all->img.img, 0, 0);
	return (0);
}