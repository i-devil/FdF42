/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 12:11:06 by ide-vill          #+#    #+#             */
/*   Updated: 2014/12/16 12:11:08 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_put_pixel(t_img *img, t_pt2d p)
{
	if ((p.x >= 0 && p.x <= WIN_WIDTH) && (p.y >= 0 && p.y <= WIN_HEIGHT))
		ft_memcpy(&img->data[p.x * 4 + p.y * img->size_line], &img->color, (size_t)(sizeof(int))); 

}

void		ft_draw(t_img *img, t_pt3d p1, t_pt3d p2)
{
	color_alt(img, ((p1.z + p2.z) / 2));
	ft_draw_line(img, ft_convert_iso(p1), ft_convert_iso(p2));
}

void		ft_draw_line_sub1(t_img *img, int dx, int dy, t_pt2d p)
{
	int cumul;
	int i;
	int xinc;
	int yinc;

	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	cumul = dx / 2;
	i = 1;
	while (i++ <= dx)
	{
		p.x += xinc;
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			p.y += yinc;
		}
		ft_put_pixel(img, p);
	}
}

void		ft_draw_line_sub2(t_img *img, int dx, int dy, t_pt2d p)
{
	int cumul;
	int i;
	int xinc;
	int yinc;

	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	cumul = dy / 2;
	i = 1;
	while (i++ <= dy)
	{
		p.y += yinc;
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			p.x += xinc;
		}
		ft_put_pixel(img, p);
	}
}

void		ft_draw_line(t_img *img, t_pt2d p1, t_pt2d p2)
{
	int		dx;
	int		dy;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	ft_put_pixel(img, p1);
	if (abs(dx) > abs(dy))
		ft_draw_line_sub1(img, dx, dy, p1);
	else
		ft_draw_line_sub2(img, dx, dy, p1);

}
