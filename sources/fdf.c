/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:00:24 by gcourrie          #+#    #+#             */
/*   Updated: 2016/05/01 19:00:27 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

static void eye_init(t_data *e)
{
	e->mid_x = 5;
	e->mid_y = 5;
	e->mid_z = -30;
	e->o_x = 0;
	e->o_y = 0;
	e->o_z = 0;
	e->a_x = 0;
	e->a_y = 0;
	e->a_z = 0;
	e->w_x = 950;
	e->w_y = 510;
	e->color = 0xFFFFFF;
	if (x > y)
	else
}

int			put_pixel(t_data *e, int pointx, int pointy)
{
	/* printf("printx = %d printy = %d\n", pointx, pointy); */
	/* if (pointx <= (e->w_x * 2) && pointx >= 0 */
	/* 	&& pointy <= (e->w_y * 2) && pointy >= 0) */
	mlx_pixel_put(e->mlx, e->win, pointx, pointy, 0x00FFFFFF);
	return (0);
}

int			expose_hook(t_data *e)
{
	draw_fdf(e);
}

int			fdf(t_data e)
{
	eye_init(&e);
	/* printf("e.x = %d  e.y = %d\n", e.x, e.y); */
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.w_x * 2, e.w_y * 2, "fdf");
	mlx_expose_hook(e.win, expose_hook, &e);
	/* e = draw_fdf(&e); */
	mlx_key_hook(e.win, bind_key, &e);
	/* printf("e.a_x = %d  e.a_y = %d e.a_z = %d\n", e.a_x, e.a_y, e.a_z); */
	mlx_loop(e.mlx);
	return (0);
}
