/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:57:28 by ide-vill          #+#    #+#             */
/*   Updated: 2014/12/16 10:57:30 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"


# include <stdio.h>


# define WIN_HEIGHT 500
# define WIN_WIDTH 500

typedef struct 		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct   	s_pt3d
{
	int				x;
	int				y;
	int				z;
}					t_pt3d;

typedef struct   	s_pt2d
{
	int				x;
	int				y;
}					t_pt2d;

typedef struct  	s_map
{
	int				lx;
	int				ly;
	int				max;
	int				min;
	t_pt3d			**tab;
	
}					t_map;

typedef struct  	s_img
{
	int				bpp;
	int				lx;
	int				ly;
	int				endian;
	int				size_line;
	void			*img;
	char			*data;
	int				type;
	int				format;
	int				color;
	t_env			e;
	t_map			map;
}					t_img;

typedef struct  	s_all
{
	t_env			e;
	t_map			map;
	t_img			img;
	int				x;
	int				y;
}					t_all;


t_pt2d		ft_convert_iso(t_pt3d p);
t_pt3d		ft_pt3d_mult(t_pt3d p, int k);
t_pt3d		ft_new_pt3d(int x, int y, int z);


void		ft_put_pixel(t_img *img, t_pt2d p);
void		ft_draw(t_img *img, t_pt3d p1, t_pt3d p2);
void		ft_draw_line(t_img *img, t_pt2d p1, t_pt2d p2);
void		ft_draw_line_sub1(t_img *img, int dx, int dy, t_pt2d p);
void		ft_draw_line_sub2(t_img *img, int dx, int dy, t_pt2d p);

void		ft_draw_map_sub(t_all *all, int a);
void		ft_draw_map(t_all *all);

t_pt3d		**fill_map(t_all *all, t_list *lst);
void		read_map(t_all *all, int fd);

void		color_alt(t_all *all);

int 		loop_hook(t_all *all);
int			key_hook(int keycode, t_all *all);
int			mouse_hook(int button, int x, int y, t_all *all);
int			expose_hook(t_all *all);

void		ft_error_fd(int fd);
void		ft_error(int argc);











#endif
