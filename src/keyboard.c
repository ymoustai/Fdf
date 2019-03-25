/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarrouj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:20:37 by yfarrouj          #+#    #+#             */
/*   Updated: 2019/03/25 05:28:01 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keyboard(int keycode, t_fdf *fdf)
{
	int x;
	int y;

	x = 0;
	y = 0;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	move_zoom(keycode, fdf);
	colors_speed(keycode, fdf);
	center_speed_iso(keycode, fdf);
	ft_draw(*fdf);
	ft_palettes(*fdf);
	ft_info(fdf);
	return (0);
}

void	move_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == 124)
		fdf->startx += 10 * fdf->speed;
	if (keycode == 123)
		fdf->startx -= 10 * fdf->speed;
	if (keycode == 126)
		fdf->starty -= 10 * fdf->speed;
	if (keycode == 53)
	{
		free(fdf->map);
		exit(0);
	}
	if (keycode == 125)
		fdf->starty += 10 * fdf->speed;
	if (keycode == 78)
		fdf->p_z--;
	if (keycode == 69)
		fdf->p_z++;
	if (keycode == 116)
		fdf->z_z++;
	if (keycode == 121)
		fdf->z_z--;
}

void	colors_speed(int keycode, t_fdf *fdf)
{
	if (keycode == 16)
		fdf->colour = 0xea0266;
	if (keycode == 15)
		fdf->colour = 0x8C002F;
	if (keycode == 5)
		fdf->colour = 0x008C00;
	if (keycode == 11)
		fdf->colour = 0x4174D8;
	if (keycode == 13)
		fdf->colour = 0xFFFFFF;
}

void	center_speed_iso(int keycode, t_fdf *fdf)
{
	if (keycode == 8)
		ft_center(fdf);
	if (keycode == 40)
	{
		if (!fdf->z_sec)
			fdf->z_sec = 1;
		else
			fdf->z_sec = 0;
	}
	if (keycode == 1)
	{
		if (fdf->speed >= 4)
			fdf->speed = 1;
		fdf->speed++;
	}
	if (keycode == 34)
		fdf->iso = 1;
	if (keycode == 35)
		fdf->iso = 0;
}
