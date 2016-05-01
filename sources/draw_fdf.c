/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <gcourrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 14:46:24 by gcourrie          #+#    #+#             */
/*   Updated: 2016/05/01 16:35:32 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

/* static int	ft_rotation(t_data *e, t_point *point, int x, int y) */
/* { */
/* 	int		z; */
/* 	double	pointx; */
/* 	double	pointy; */
/* 	double	pointz; */

/* 	z = e->table[y][x]; */
/* 	pointx = cos(e->a_x) * cos(e->a_z) * (x /\* - e->mid_x *\/) - */
/* 				sin(e->a_x) * (y /\* - e->mid_y *\/) + cos(e->a_x) * */
/* 				sin(e->a_z) * (z /\* - e->mid_z *\/) + (x - e->mid_x); */
/* 	pointy = (cos(e->a_y) * sin(e->a_x) * cos(e->a_z) + */
/* 				sin(e->a_y) * sin(e->a_z)) * (x /\* - e->mid_x *\/) + */
/* 				cos(e->a_y) * cos(e->a_x) * (y /\* - e->mid_y *\/) + */
/* 				(cos(e->a_y) * sin(e->a_x) * sin(e->a_x) - */
/* 				sin(e->a_y) * cos(e->a_z)) * (z /\* - e->mid_z *\/) + */
/* 				(y - e->mid_y); */
/* 	pointz = (sin(e->a_y) * sin(e->a_x) * cos(e->a_z) - */
/* 				cos(e->a_y) * sin(e->a_z)) * (x /\* - e->mid_x *\/) + */
/* 				sin(e->a_y) * cos(e->a_x) * (y /\* - e->mid_y *\/) + */
/* 				(sin(e->a_y) * sin(e->a_x) * sin(e->a_x) + */
/* 				cos(e->a_y) * cos(e->a_z)) * (z /\* - e->mid_z *\/) + */
/* 				(z - e->mid_z); */
/* 	point->x = (int)((pointx * 6) / (6 + pointz) * e->w_x / 3.5 + e->w_x); */
/* 	point->y = (int)((pointy * 6) / (6 + pointz) * e->w_y / 3.5 + e->w_y); */
/*     /\* printf("point->x = %d  point->y = %d\n", (int)point->x, (int)point->y); *\/ */
/* 	return (0); */
/* } */

static int	rotation_and_draw(t_data *e, int x, int y)
{
	t_point	actu;
	t_point	right;
	t_point	left;

	ft_rotation(e, &actu, x, y);
    /* printf("e.x = %d  e.y = %d  x = %d  y = %d\n", e->x, e->y, x, y); */
	if ((x + 1) < e->x)
	{
		ft_rotation(e, &right, x + 1, y);
		draw_line(e, &actu, &right);
	}
	if ((y + 1) < e->y)
	{
		ft_rotation(e, &left, x, y + 1);
		draw_line(e, &actu, &left);
	}
	return (0);
}

int			draw_fdf(t_data *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < e->y)
	{
		while (x < e->x)
		{
			rotation_and_draw(e, x, y);
			x += 1;
		}
		x = 0;
		y += 1;
	}
	return (0);
}
