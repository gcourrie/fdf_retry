/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:47:27 by gcourrie          #+#    #+#             */
/*   Updated: 2016/05/01 18:37:35 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_

# include "../includes/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct		s_point
{
	int			x;
	int			y;
	/* double			z; */
}					t_point;

typedef struct		s_mat33
{
	double			m1_1;
	double			m1_2;
	double			m1_3;
	double			m2_1;
	double			m2_2;
	double			m2_3;
	double			m3_1;
	double			m3_2;
	double			m3_3;
}					t_mat33;

typedef struct		s_mat31
{
	double			m1_1;
	double			m2_1;
	double			m3_1;
}					t_mat31;

typedef struct		s_mat13
{
	double			m1_1;
	double			m1_2;
	double			m1_3;
}					t_mat13;

typedef struct		s_line
{
	double			a;
	double			b;
}					t_line;

typedef struct		s_data
{
	int				x;
	int				y;
	int				x2;
	int				y2;
	void			*mlx;
	void			*win;
	int				**table;
	double			mid_x;
	double			mid_y;
	double			mid_z;
	double			o_x;
	double			o_y;
	double			o_z;
	double			a_x;
	double			a_y;
	double			a_z;
	double			p_x;
	double			p_y;
	double			p_z;
	int				w_x;
	int				w_y;
	int				color;
}					t_data;


typedef struct		s_lst
{
	char			**str;
	struct s_lst	*next;
}					t_lst;

int					fdf(t_data e);
int					bind_key(int keycode, t_data *e);
int					draw_fdf(t_data *e);
int					expose_hook(t_data *e);
int					draw_line(t_data *e, t_point *rst, t_point *nd);
int					put_pixel(t_data *e, int pointx, int pointy);
int					ft_rotation(t_data *e, t_point *point, int x, int y);

#endif
