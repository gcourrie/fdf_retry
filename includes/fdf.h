/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:47:27 by gcourrie          #+#    #+#             */
/*   Updated: 2016/04/15 09:07:41 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_

# include "../includes/libft.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

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
	double			a_x;
	double			a_y;
	double			a_z;
	double			p_x;
	double			p_y;
	double			p_z;
	int				w_x;
	int				w_y;

}					t_data;


typedef struct		s_lst
{
	char			**str;
	struct s_lst	*next;
}					t_lst;

int					fdf(t_data e);
int					key_hook(int keycode, t_data *e);
int					draw_fdf(t_data *e);
int					expose_hook(t_data *e);

#endif
