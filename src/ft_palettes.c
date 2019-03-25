/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_palettes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarrouj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:26:35 by ymoustai          #+#    #+#             */
/*   Updated: 2019/03/25 05:27:28 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_panel(t_fdf fdf)
{
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10,
	28, 0xFFFFFF, "PAGE(Z UP/DOWN)");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10,
	44, 0xFFFFFF, "ZOOM(+/-)");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10,
	60, 0xFFFFFF, "SPEED UP(S)");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10,
	76, 0xFFFFFF, "DEPLACEMENT(<-UP->)");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10,
	92, 0xFFFFFF, "POSITION(RIGHT CLICK)");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10,
	108, 0xFFFFFF, "COLORS(LEFT CLICK)");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 124,
	0xFFFFFF, "CENTER(C)");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 140,
	0xFFFFFF, "PROJECTION(P / I)");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 156,
	0xFFFFFF, "COLOUR ALTITUDE(K)");
}

void	ft_help_panel(t_fdf fdf, char *c, int colour)
{
	t_map p[1];

	p[0].x = 10;
	p[0].y = 10;
	p[0].colour = colour;
	ft_drawsquare(fdf, p[0], 18);
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 14, 8,
	0xFFFFFF, c);
}

void	ft_drawsquare(t_fdf fdf, t_map p, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, j + p.x, i + p.y, p.colour);
		}
	}
}

void	ft_palettes(t_fdf fdf)
{
	int		i;
	t_map	*t;

	t = malloc(sizeof(t_map) * 7);
	i = -1;
	while (++i < 6)
	{
		t[i].x = (28) + (i * 36) + 18;
		t[i].y = (10);
	}
	i = -1;
	t[0].colour = 0xea0266;
	t[1].colour = 0x8C002F;
	t[2].colour = 0x008C00;
	t[3].colour = 0x4174D8;
	t[4].colour = 0xffffff;
	while (++i < 5)
		ft_drawsquare(fdf, t[i], 18);
}
