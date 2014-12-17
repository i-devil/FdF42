/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 11:51:34 by ide-vill          #+#    #+#             */
/*   Updated: 2014/12/17 16:56:09 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move_up(t_all *all)
{
	all->img.posimgy -= 5;
	all->img.re = 1;
}

void		move_down(t_all *all)
{
	all->img.posimgy += 5;
	all->img.re = 1;
}

void		move_right(t_all *all)
{
	all->img.posimgx += 5;
	all->img.re = 1;
}

void		move_left(t_all *all)
{
	all->img.posimgx -= 5;
	all->img.re = 1;
}
