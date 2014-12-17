/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:57:40 by ide-vill          #+#    #+#             */
/*   Updated: 2014/12/16 10:57:42 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_map_sub(t_all *all, int a)
{
	int		x;
	int		y;

	if (a == all->map.lx)
	{
		y = 0;
		while (y < all->map.ly)
		{
			ft_draw(&all->img,
					ft_pt3d_mult(all->map.tab[a][y], 30),
					ft_pt3d_mult(all->map.tab[a][y + 1], 30));
			y++;
		}
	}
	if (a == all->img.ly)
	{
		x = 0;
		while (x < all->map.lx)
		{
			ft_draw(&all->img,
					ft_pt3d_mult(all->map.tab[x][a], 30),
					ft_pt3d_mult(all->map.tab[x + 1][a], 30));
			x++;
		}
	}
}

void		ft_draw_map(t_all *all)
{
	int		x;
	int		y;

	x = 0;
	while (x < (all->map.lx))
	{
		y = 0;
		while (y < (all->map.ly))
		{
			ft_draw(&all->img,
				ft_pt3d_mult(all->map.tab[x][y], 30),
				ft_pt3d_mult(all->map.tab[x + 1][y], 30));
			ft_draw(&all->img,
				ft_pt3d_mult(all->map.tab[x][y], 30),
				ft_pt3d_mult(all->map.tab[x][y + 1], 30));
			y++;
		}
		x++;
	}
	ft_draw_map_sub(all, x);
	ft_draw_map_sub(all, y);
}
