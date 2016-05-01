/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 03:13:09 by gcourrie          #+#    #+#             */
/*   Updated: 2016/05/01 18:39:39 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int		bind_key(int keycode, t_data *e)
{
	(void)e;
	printf("key :%d\n", keycode);
	if (/* keycode == 126 */keycode == 65361)
		e->o_x += 1;
	if (/* keycode == 125 */keycode == 65363)
		e->o_x -= 1;
	if (keycode == 65362)
		e->o_y += 1;
	if (keycode == 65364)
		e->o_y -= 1;
	if (keycode == 65365)
		e->o_z += 1;
	if (keycode == 65366)
		e->o_z -= 1;
	if (keycode == 122)
		e->a_x += 0.1;
	if (keycode == 115)
		e->a_x -= 0.1;
	if (keycode == 113)
		e->a_y += 0.1;
	if (keycode == 100)
		e->a_y -= 0.1;
	if (keycode == 97)
		e->a_z += 0.1;
	if (keycode == 101)
		e->a_z -= 0.1;
	if (/* keycode == 53 */keycode == 65307)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
    printf("e.a_x = %e  e.a_y = %e e.a_z = %e\n", e->a_x, e->a_y, e->a_z);
	mlx_clear_window(e->mlx, e->win);
	draw_fdf(e);
	return (0);
}
