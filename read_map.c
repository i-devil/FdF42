/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:58:00 by ide-vill          #+#    #+#             */
/*   Updated: 2014/12/16 10:58:02 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pt3d			**fill_map(t_all *all, t_list *lst)
{
	int 		i;
	t_pt3d		p;
	t_list		*tmp;

	i = 0;
	all->map.tab = (t_pt3d **)malloc(sizeof(t_pt3d *) * all->map.lx);
	while (i < all->map.lx)
		all->map.tab[i++] = (t_pt3d *)malloc(sizeof(t_pt3d) * all->map.ly);
	while (lst)
	{
		p = *(t_pt3d *)(lst->content);
		if (all->map.min > p.z)
			all->map.min = p.z;
		if (all->map.max < p.z)
			all->map.max = p.z;
		p.z *= -1;
		all->map.tab[p.x][p.y] = p;
		tmp = lst;
		lst = lst->next;
		ft_lstsimpledelone(&tmp);
	}
	all->map.lx = p.x;
	all->map.ly = p.y;
	return (all->map.tab);
}

void			read_map(t_all *all, int fd)
{
	t_list		*lst;
	char		*line;
	char		**tmp;
	int			ret;
	t_pt3d		p;

	lst = NULL;
	all->map.ly = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return ;
		tmp = ft_strsplit(line, ' ');
		free(line);
		all->map.lx = 0;
		while (*tmp)
		{
			p = ft_new_pt3d(all->map.lx, all->map.ly, ft_atoi(*tmp));
			ft_lstsmartpushback(&lst, ft_lstnew((void *)&p, sizeof(t_pt3d)));
			all->map.lx++;
			free(*tmp++);
		}
		all->map.ly++;
	}
	all->map.tab = fill_map(all, lst);
	close(fd);
}

