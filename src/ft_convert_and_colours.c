/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_and_colours.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoustai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 23:37:04 by ymoustai          #+#    #+#             */
/*   Updated: 2019/03/21 23:37:07 by ymoustai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_iso(t_map *p, t_fdf fdf)
{
	int previous_x;
	int previous_y;
	int x;
	int y;

	previous_x = 0;
	previous_x = 0;
	if (fdf.iso == 1)
	{
		previous_x = p->x;
		previous_y = p->y;
		p->x = (previous_x - previous_y) * cos(0.523599);
		p->y = -p->z + (previous_x + previous_y) * sin(0.523599);
	}
	else
	{
		p->y += p->z;
		p->x -= p->z;
	}
}

t_map	ft_convert(t_map point, t_fdf fdf)
{
	t_map p;

	p.x = point.x * fdf.p_z;
	p.y = point.y * fdf.p_z;
	p.z = point.z * fdf.z_z;
	ft_iso(&p, fdf);
	p.x += fdf.startx;
	p.y += fdf.starty;
	return (p);
}
