/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <gcourrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 18:27:58 by gcourrie          #+#    #+#             */
/*   Updated: 2016/05/01 15:35:28 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	draw_line_x(t_data *e, t_point *a, t_point *b, int c)
{
	int		x;
	int		xmax;
	double	y;

	(a->x >= b->x) ? (x = b->x) : (x = a->x);
	(a->x >= b->x) ? (xmax = a->x) : (xmax = b->x);
	while (x < xmax)
	{
		y = ((b->y - a->y) * x + c) / (b->x - a->x);
		mlx_pixel_put(e->mlx, e->win, x, (int)y, e->color);
		/* if (y < (double)((int)y)) */
		/* 	mlx_pixel_put(e->mlx, e->win, x, (int)y - 1, 0xFF0000); */
		/* if (y > (double)((int)y)) */
		/* 	mlx_pixel_put(e->mlx, e->win, x, (int)y + 1, 0xFF0000); */
		/* /\* put_pixel(e, x++, y); *\/ */
		x++;
	}
	return (0);
}

static int	draw_line_y(t_data *e, t_point *a, t_point *b, int c)
{
	double	x;
	int		y;
	int		ymax;

	(a->y >= b->y) ? (y = b->y) : (y = a->y);
	(a->y >= b->y) ? (ymax = a->y) : (ymax = b->y);
	while (y < ymax)
	{
		x = ((b->x - a->x) * y - c) / (b->y - a->y);
        mlx_pixel_put(e->mlx, e->win, (int)x, y, e->color);
		/* if (x < (double)((int)x)) */
		/* 	mlx_pixel_put(e->mlx, e->win, (int)x - 1, y, 0xFF0000); */
		/* if (x > (double)((int)x)) */
		/* 	mlx_pixel_put(e->mlx, e->win, (int)x + 1, y, 0xFF0000); */
		/* /\* put_pixel(e, x, y++); *\/ */
		y++;
	}
	return (0);
}

int			draw_line(t_data *e, t_point *a, t_point *b)
{
	int		c;

	c = -(b->y - a->y) * a->x + (b->x - a->x) * a->y;
	if (ABS(b->x - a->x) >= ABS(b->y - a->y))
		draw_line_x(e, a, b, c);
	else if (ABS(b->x - a->x) < ABS(b->y - a->y))
		draw_line_y(e, a, b, c);
	return (0);
}
