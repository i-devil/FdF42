/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:57:48 by ide-vill          #+#    #+#             */
/*   Updated: 2014/12/16 10:57:50 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//alt_up
//alt_down
//move left rightup down

void		alt_up(t_img *img)
{
	img->alt += 1;
}

void		alt_down(t_img *img)
{
	img->alt -= 1;
}

void		color_alt(t_img *img, int k)
{
	//if (img->alt == 0)
		//img->color = 0x7FC6BC;
	k = k;
	img->color = 0x7FC6BC;
}
