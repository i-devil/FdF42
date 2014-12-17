/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:57:48 by ide-vill          #+#    #+#             */
/*   Updated: 2014/12/17 16:59:13 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		alt_up(t_img *img)
{
	img->alt += 1;
	img->re = 1;
}

void		alt_down(t_img *img)
{
	img->alt -= 1;
	img->re = 1;
}

void		adj_plus(t_img *img)
{
	if (img->adj > 1.0)
		img->adj -= 0.1;
	img->re = 1;
}

void		adj_less(t_img *img)
{
	if (img->adj < 3.0)
		img->adj += 0.1;
	img->re = 1;
}

void		color_alt(t_img *img, int z)
{
	if (img->alt == 0)
		img->color = 0x7FC6BC;
	else if ((-z / img->alt) <= -4)
		img->color = 0x3D8189;
	else if ((-z / img->alt) <= -2)
		img->color = 0x4BB5C1;
	else if ((-z / img->alt) <= 0)
		img->color = 0x7FC6BC;
	else if ((-z / img->alt) <= 1)
		img->color = 0xffe58a;
	else if ((-z / img->alt) <= 4)
		img->color = 0x71A12F;
	else if ((-z / img->alt) <= 6)
		img->color = 0x557A23;
	else if ((-z / img->alt) <= 8)
		img->color = 0x896A45;
	else if ((-z / img->alt) <= 10)
		img->color = 0xA98458;
	else if ((-z / img->alt) <= 12)
		img->color = 0xCAA986;
	else
		img->color = 0xEDF7F2;
}
