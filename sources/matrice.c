/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <gcourrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 13:05:33 by gcourrie          #+#    #+#             */
/*   Updated: 2016/05/01 18:59:00 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

static t_mat33	mat_3_3_and_3_3(t_mat33 a, t_mat33 b)
{
	t_mat33	c;

	c.m1_1 = a.m1_1 * b.m1_1 + a.m1_2 * b.m2_1 + a.m1_3 * b.m3_1;
	c.m1_2 = a.m1_1 * b.m1_2 + a.m1_2 * b.m2_2 + a.m1_3 * b.m3_2;
	c.m1_3 = a.m1_1 * b.m1_3 + a.m1_2 * b.m2_3 + a.m1_3 * b.m3_3;
	c.m2_1 = a.m2_1 * b.m1_1 + a.m2_2 * b.m2_1 + a.m2_3 * b.m3_1;
	c.m2_2 = a.m2_1 * b.m1_2 + a.m2_2 * b.m2_2 + a.m2_3 * b.m3_2;
	c.m2_3 = a.m2_1 * b.m1_3 + a.m2_2 * b.m2_3 + a.m2_3 * b.m3_3;
	c.m3_1 = a.m3_1 * b.m1_1 + a.m3_2 * b.m2_1 + a.m3_3 * b.m3_1;
	c.m3_2 = a.m3_1 * b.m1_2 + a.m3_2 * b.m2_2 + a.m3_3 * b.m3_2;
	c.m3_3 = a.m3_1 * b.m1_3 + a.m3_2 * b.m2_3 + a.m3_3 * b.m3_3;
	return (c);
}

static t_mat31	mat_3_3_and_3_1(t_mat33 a, t_mat31 b)
 {
	t_mat31	c;

	c.m1_1 = a.m1_1 * b.m1_1 + a.m1_2 * b.m2_1 + a.m1_3 * b.m3_1;
	c.m2_1 = a.m2_1 * b.m1_1 + a.m2_2 * b.m2_1 + a.m2_3 * b.m3_1;
	c.m3_1 = a.m3_1 * b.m1_1 + a.m3_2 * b.m2_1 + a.m3_3 * b.m3_1;
	return (c);
}

/* static t_mat33	mat_3_3_and_3_3(t_mat33 a, t_mat33 b) */
/* { */
/* 	t_mat33	c; */

/* 	c.m1_1 = a.m1_1 * b.m1_1 + a.m2_1 * b.m2_1 + a.m3_1 * b.m3_1; */
/* 	c.m1_2 = a.m1_2 * b.m1_1 + a.m2_2 * b.m2_1 + a.m3_2 * b.m3_1; */
/* 	c.m1_3 = a.m1_3 * b.m1_1 + a.m2_3 * b.m2_1 + a.m3_3 * b.m3_1; */
/* 	c.m2_1 = a.m1_1 * b.m1_2 + a.m2_1 * b.m2_2 + a.m3_1 * b.m3_2; */
/* 	c.m2_2 = a.m1_2 * b.m1_2 + a.m2_2 * b.m2_2 + a.m3_2 * b.m3_2; */
/* 	c.m2_3 = a.m1_3 * b.m1_2 + a.m2_3 * b.m2_2 + a.m3_3 * b.m3_2; */
/* 	c.m3_1 = a.m1_1 * b.m1_3 + a.m2_1 * b.m2_3 + a.m3_1 * b.m3_3; */
/* 	c.m3_2 = a.m1_2 * b.m1_3 + a.m2_2 * b.m2_3 + a.m3_2 * b.m3_3; */
/* 	c.m3_3 = a.m1_3 * b.m1_3 + a.m2_3 * b.m2_3 + a.m3_3 * b.m3_3; */
/* 	return (c); */
/* } */

/* static t_mat31	mat_3_3_and_3_1(t_mat33 a, t_mat31 b) */
/*  { */
/* 	t_mat31	c; */

/* 	c.m1_1 = a.m1_1 * b.m1_1 + a.m2_1 * b.m2_1 + a.m3_1 * b.m3_1; */
/* 	c.m2_1 = a.m1_2 * b.m1_1 + a.m2_2 * b.m2_1 + a.m3_2 * b.m3_1; */
/* 	c.m3_1 = a.m1_3 * b.m1_1 + a.m2_3 * b.m2_1 + a.m3_3 * b.m3_1; */
/* 	return (c); */
/* } */

static t_mat13	mat_1_3_and_3_3(t_mat13 a, t_mat33 b)
 {
	t_mat13	c;

	c.m1_1 = a.m1_1 * b.m1_1 + a.m1_2 * b.m1_2 + a.m1_3 * b.m1_3;
	c.m1_2 = a.m1_1 * b.m2_1 + a.m1_2 * b.m2_2 + a.m1_3 * b.m2_3;
	c.m1_3 = a.m1_1 * b.m3_1 + a.m1_2 * b.m3_2 + a.m1_3 * b.m3_3;
	return (c);
}

static t_mat33	init_mat_x(t_data *e)
{
	t_mat33	a;

	a.m1_1 = 1;
	a.m1_2 = 0;
	a.m1_3 = 0;
	a.m2_1 = 0;
	a.m2_2 = cos(e->a_x);
	a.m2_3 = -sin(e->a_x);
	a.m3_1 = 0;
	a.m3_2 = sin(e->a_x);
	a.m3_3 = cos(e->a_x);
	return (a);
}

static t_mat33	init_mat_y(t_data *e)
{
	t_mat33	a;

	a.m1_1 = cos(e->a_y);
	a.m1_2 = 0;
	a.m1_3 = sin(e->a_y);
	a.m2_1 = 0;
	a.m2_2 = 1;
	a.m2_3 = 0;
	a.m3_1 = -sin(e->a_y);
	a.m3_2 = 0;
	a.m3_3 = cos(e->a_y);
	return (a);
}

static t_mat33	init_mat_z(t_data *e)
{
	t_mat33	a;

	a.m1_1 = cos(e->a_z);
	a.m1_2 = -sin(e->a_z);
	a.m1_3 = 0;
	a.m2_1 = sin(e->a_z);
	a.m2_2 = cos(e->a_z);
	a.m2_3 = 0;
	a.m3_1 = 0;
	a.m3_2 = 0;
	a.m3_3 = 1;
	return (a);
}

static t_mat31	init_mat_translation(t_data *e, int x, int y, int z)
{
	t_mat31	a;

	a.m1_1 = x;
	a.m2_1 = y;
	a.m3_1 = z;
	return (a);
}

/* static t_mat31	init_mat_translation2(t_data *e, int x, int y, int z) */
/* { */
/* 	t_mat31	a; */

/* 	a.m1_1 = x - e->mid_x; */
/* 	a.m2_1 = y - e->mid_y; */
/* 	a.m3_1 = z - e->mid_z; */
/* 	return (a); */
/* } */

/* static t_mat13	init_mat_translation3(t_data *e, int x, int y, int z) */
/* { */
/* 	t_mat13	a; */

/* 	a.m1_1 = x; */
/* 	a.m1_2 = y; */
/* 	a.m1_3 = z; */
/* 	return (a); */
/* } */

/* static t_mat13	init_mat_translation4(t_data *e, int x, int y, int z) */
/* { */
/* 	t_mat13	a; */

/* 	a.m1_1 = x - e->mid_x; */
/* 	a.m1_2 = y - e->mid_y; */
/* 	a.m1_3 = z - e->mid_z; */
/* 	return (a); */
/* } */

int				ft_rotation(t_data *e, t_point *point, int x, int y)
{
	int		z;
	t_mat31	a;

	z = e->table[y][x];	
	a = mat_3_3_and_3_1(mat_3_3_and_3_3(mat_3_3_and_3_3(init_mat_x(e),
														init_mat_y(e)),
										init_mat_z(e)),
						init_mat_translation(e, x, y, z));
	/* a = mat_3_3_and_3_1(init_mat_x(e), init_mat_translation(e, x, y, z)); */
	if (x == 1 && y == 1)
		printf("pointx = %e  pointy = %e\n", a.m1_1, a.m2_1);
	a.m1_1 = a.m1_1 + e->o_x;
	a.m2_1 = a.m2_1 + e->o_y;
	a.m3_1 = a.m3_1 + e->o_z;
    /* point->x = (int)((ABS(a.m1_1) * 6) / (6 + a.m3_1) * e->w_x / 3.5 + e->w_x); */
    /* point->y = (int)((ABS(a.m2_1) * 6) / (6 + a.m3_1) * e->w_y / 3.5 + e->w_y); */
    point->x = (int)((a.m1_1 * 6) / (6 - (e->mid_z - a.m3_1)) * 300 + e->w_x);
	point->y = (int)((a.m2_1 * 6) / (6 - (e->mid_z - a.m3_1)) * 300 + e->w_y);
	/* t_mat13	a; */

	/* a = mat_1_3_and_3_3(mat_1_3_and_3_3( */
	/* 					mat_1_3_and_3_3( */
	/* 					init_mat_translation3(e, x, y, z), */
	/* 					init_mat_x(e)), */
	/* 					init_mat_y(e)), */
	/* 					init_mat_z(e)); */
	/* a.m1_1 = a.m1_1 + x - e->mid_x; */
	/* a.m1_2 = a.m1_2 + y - e->mid_y; */
	/* a.m1_3 = a.m1_3 + z - e->mid_z; */
    /* point->x = (int)((a.m1_1 * 6) / (6 + a.m1_3) * e->w_x / 3.5 + e->w_x); */
    /* point->y = (int)((a.m1_2 * 6) / (6 + a.m1_3) * e->w_y / 3.5 + e->w_y); */
}
