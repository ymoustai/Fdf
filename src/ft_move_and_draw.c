/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_and_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoustai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 23:31:44 by ymoustai          #+#    #+#             */
/*   Updated: 2019/03/22 13:01:09 by yfarrouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_fdf fdf)
{
	int i;
	int j;

	i = -1;
	while (++i < fdf.count[0])
	{
		j = -1;
		while (++j < fdf.count[1])
		{
			if (j < fdf.count[1] - 1)
				line(fdf, ft_convert(fdf.map[i][j], fdf),
						ft_convert(fdf.map[i][j + 1], fdf));
			if (i < fdf.count[0] - 1)
				line(fdf, ft_convert(fdf.map[i][j], fdf),
						ft_convert(fdf.map[i + 1][j], fdf));
		}
	}
}

void	ft_colorpanel(t_fdf *fdf, int x, int y)
{
	if (y >= 10 && y <= 28 && x >= 46 && x <= 64)
		ft_setcolor(fdf, 0xea0266);
	else if (y >= 10 && y <= 28 && x >= 82 && x <= 100)
		ft_setcolor(fdf, 0x8C002F);
	else if (y >= 10 && y <= 118 && x >= 118 && x <= 136)
		ft_setcolor(fdf, 0x008C00);
	else if (y >= 10 && y <= 28 && x >= 154 && x <= 172)
		ft_setcolor(fdf, 0x4174D8);
	else if (y >= 10 && y <= 28 && x >= 190 && x <= 208)
		ft_setcolor(fdf, 0xffffff);
	else if (y >= 10 && y <= 28 && x >= 10 && x <= 28)
	{
		if (!fdf->panel)
			fdf->panel = 1;
		else
			fdf->panel = 0;
	}
}

void	ft_info(t_fdf *fdf)
{
	if (fdf->panel == 0)
		ft_help_panel(*fdf, "?", 0x000000);
	else
	{
		fdf->panel = 1;
		ft_help_panel(*fdf, "X", 0x000000);
		ft_palettes(*fdf);
		ft_print_panel(*fdf);
	}
}

int		ft_mouse(int mousecode, int x, int y, t_fdf *fdf)
{
	mlx_clear_window(fdf->win_ptr, fdf->win_ptr);
	ft_palettes(*fdf);
	if (mousecode == 2)
	{
		fdf->startx = x - fdf->count[1] / 2;
		fdf->starty = y - fdf->count[0] / 2;
	}
	else if (mousecode == 1)
	{
		ft_colorpanel(fdf, x, y);
	}
	ft_draw(*fdf);
	ft_info(fdf);
	return (0);
}

void	ft_setcolor(t_fdf *fdf, int color)
{
	fdf->colour = color;
}
