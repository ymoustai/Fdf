/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoustai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 02:54:41 by ymoustai          #+#    #+#             */
/*   Updated: 2019/03/22 13:49:11 by yfarrouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct	s_line
{
	int		sx;
	int		sy;
	int		dx;
	int		dy;
	int		err;
	int		e2;
}				t_line;

typedef struct	s_coor
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;
}				t_coor;

typedef struct	s_map
{
	int x;
	int y;
	int z;
	int	colour;
}				t_map;

typedef	struct	s_fdf
{
	t_coor	pti;
	void	*mlx_ptr;
	void	*win_ptr;
	int		colour;
	int		i;
	int		win_h;
	int		win_l;
	int		p_z;
	int		z_z;
	t_map	**map;
	int		*count;
	int		iso;
	int		startx;
	int		starty;
	int		z_sec;
	int		panel;
	int		speed;
	int		fd;
	int		y;
	int		ac;
	char	**av;
	int		i_1;
}				t_fdf;

void			ft_window_size(t_fdf *fdf, int *count);
void			ft_initwin(t_fdf *fdf, char **av);
void			ft_initfdf(t_fdf *fdf);
char			*ft_path(char *av);
void			move_zoom(int keycode, t_fdf *fdf);
void			colors_speed(int keycode, t_fdf *fdf);
void			center_speed_iso(int keycode, t_fdf *fdf);
void			error(void);
void			ft_center(t_fdf *fdf);
void			ft_iso(t_map *p, t_fdf fdf);
int				keyboard(int keycode, t_fdf *fdf);
void			line(t_fdf fdf, t_map pti, t_map ptf);
void			ft_draw(t_fdf fdf);
void			ft_move_right(t_map ***map, int *count);
void			ft_move_left(t_map ***map, int *count);
void			ft_move_up(t_map ***map, int *count);
void			ft_move_down(t_map ***map, int *count);
t_map			ft_convert(t_map p, t_fdf fdf);
void			ft_print_panel(t_fdf fdf);
void			ft_colorpanel(t_fdf *fdf, int x, int y);
int				ft_mouse(int mousecode, int x, int y, t_fdf *fdf);
void			ft_setcolor(t_fdf *fdf, int color);
void			ft_drawsquare(t_fdf fdf, t_map p, int size);
void			ft_palettes(t_fdf fdf);
void			ft_help_panel(t_fdf fdf, char *c, int colour);
void			ft_info(t_fdf *fdf);
int				ft_rgb(t_fdf fdf, int z);

#endif
