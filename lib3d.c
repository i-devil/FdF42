/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:58:08 by ide-vill          #+#    #+#             */
/*   Updated: 2014/12/16 10:58:10 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pt2d		ft_convert_iso(t_pt3d p)
{
	t_pt2d	point;
	float	cst1;
	float	cst2;

	cst1 = 1;
	cst2 = 1;
	point.x = (cst1 * p.x) - (cst2 * p.y);
	point.y = p.z + ((cst1 / 2) * p.x) + ((cst2 / 2) * p.y);
	point.x += (WIN_WIDTH / 2);
	point.y += (WIN_HEIGHT / 4);
	return (point);
}

t_pt3d		ft_pt3d_mult(t_pt3d p, int k)
{
	p.x *= k;
	p.y *= k;
	return (p);
}

t_pt3d		ft_new_pt3d(int x, int y, int z)
{
	t_pt3d	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}
