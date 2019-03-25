/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pxl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarrouj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:10:20 by yfarrouj          #+#    #+#             */
/*   Updated: 2019/03/25 05:27:42 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*count_v1(int fd)
{
	char	*line;
	int		*count;
	char	**split;
	int		i;

	i = 0;
	count = (int*)malloc(sizeof(int) * 2);
	while (get_next_line(fd, &line))
	{
		if (count[0] == 0)
		{
			split = ft_strsplit(line, ' ');
			while (split[i])
				i++;
			count[1] = i;
		}
		count[0]++;
	}
	return (count);
}

void	count_v2(int fd, t_map ***map, int *count, t_fdf *fdf)
{
	char	*line;
	char	**split;
	int		x;
	int		y;

	y = 0;
	fdf->i_1 = -1;
	map[0] = (t_map**)malloc(sizeof(t_map*) * count[0]);
	while (fdf->i_1++ < count[0])
		map[0][fdf->i_1] = (t_map*)malloc(sizeof(t_map) * count[1]);
	while (get_next_line(fd, &line))
	{
		x = -1;
		split = ft_strsplit(line, ' ');
		while (split[++x])
		{
			map[0][y][x].y = y * 4;
			map[0][y][x].x = x * 4;
			map[0][y][x].z = ft_atoi(split[x]) * 2;
		}
		y++;
	}
}

void	ft_window_size(t_fdf *fdf, int *count)
{
	fdf->win_h = count[1] * fdf->p_z + 1000;
	fdf->win_l = count[0] * fdf->p_z + 800;
}

void	line(t_fdf fdf, t_map pti, t_map ptf)
{
	t_line line;

	line.dx = abs(ptf.x - pti.x);
	line.dy = abs(ptf.y - pti.y);
	line.sx = (pti.x < ptf.x) ? 1 : -1;
	line.sy = (pti.y < ptf.y) ? 1 : -1;
	line.err = line.dx - line.dy;
	while (1)
	{
		mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, pti.x, pti.y,
		ft_rgb(fdf, pti.z));
		if ((pti.x == ptf.x) && (pti.y == ptf.y))
			break ;
		line.e2 = line.err;
		if (line.e2 > -line.dx)
		{
			line.err -= line.dy;
			pti.x += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			pti.y += line.sy;
		}
	}
}

int		main(int ac, char **av)
{
	t_fdf	fdf;

	ft_initfdf(&fdf);
	fdf.fd = open(av[1], O_RDONLY);
	if ((ac != 2) || (fdf.fd == -1))
	{
		ft_putendl("usage: ./fdf map.fdf");
		exit(1);
	}
	fdf.mlx_ptr = mlx_init();
	fdf.count = count_v1(fdf.fd);
	close(fdf.fd);
	fdf.fd = open(av[1], O_RDONLY);
	count_v2(fdf.fd, &fdf.map, fdf.count, &fdf);
	ft_initwin(&fdf, av);
	return (0);
}
