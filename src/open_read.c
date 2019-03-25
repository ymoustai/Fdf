/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarrouj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:13:23 by ymoustai          #+#    #+#             */
/*   Updated: 2019/03/25 05:28:21 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_path(char *av)
{
	char	**path;
	char	**pathy;
	int		i;

	path = ft_strsplit(av, '/');
	i = 0;
	while (path[i])
		i++;
	pathy = ft_strsplit(path[i - 1], '.');
	if (pathy[1] && ((ft_strcmp(pathy[1], "fdf") == 0)))
		return (path[i - 1]);
	else
	{
		ft_putendl("usage: ./fdf map.fdf");
		exit(1);
	}
}

void	ft_initfdf(t_fdf *fdf)
{
	fdf->p_z = 2;
	fdf->z_z = 2;
	fdf->iso = 1;
	fdf->panel = 0;
	fdf->speed = 1;
	fdf->z_sec = 0;
	fdf->colour = 0xea0266;
}

void	ft_initwin(t_fdf *fdf, char **av)
{
	ft_window_size(fdf, fdf->count);
	ft_center(fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_h,
	fdf->win_l, ft_path(av[1]));
	ft_info(fdf);
	ft_draw(*fdf);
	mlx_hook(fdf->win_ptr, 2, 1, keyboard, fdf);
	mlx_mouse_hook(fdf->win_ptr, (*ft_mouse), fdf);
	mlx_loop(fdf->mlx_ptr);
}

int		ft_rgb(t_fdf fdf, int z)
{
	if (fdf.z_sec == 1 && z != 0)
		return (0x7F00FF);
	if (fdf.z_sec == 1 && z == 0)
		return (0x000000);
	return (fdf.colour);
}

void	ft_center(t_fdf *fdf)
{
	fdf->startx = (fdf->win_l - (fdf->count[1] * fdf->p_z)) / 3;
	fdf->starty = (fdf->win_h - (fdf->count[0] * fdf->p_z)) / 3.5;
}
