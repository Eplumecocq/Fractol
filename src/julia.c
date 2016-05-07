/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 15:29:18 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/07 16:23:01 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_juju(t_complex *comp)
{
	comp->x1 = -1.5 / comp->k + comp->coeff2;
	comp->x2 = 1.5 / comp->k + comp->coeff2;
	comp->y1 = -1.5 / comp->k + comp->coeff1;
	comp->y2 = 1.5 / comp->k + comp->coeff1;
	comp->zoom = 300 * comp->k;
	comp->imax = 150;
	comp->zoom_x = (comp->x2 - comp->x1) * comp->zoom;
	comp->zoom_y = (comp->y2 - comp->y1) * comp->zoom;
}

static void		init_coco(t_complex *comp, int x, int y)
{
	comp->c_r = comp->jc_r;
	comp->c_i = comp->jc_i;
	comp->z_r = x / comp->zoom + comp->x1;
	comp->z_i = y / comp->zoom + comp->y1;
}

void			julia2(t_env *env)
{
	t_complex	*comp;
	int			x;
	int			y;

	comp = env->comp;
	x = 0;
	y = 0;
	comp->z = 0;

	init_juju(comp);
	while (x < IMAGE_X)
	{
		y = 0;
		while (y < IMAGE_Y)
		{
			comp->z = 0;
			init_coco(comp, x, y);
			while (((comp->z_r * comp->z_r) + (comp->z_i * comp->z_i) < 4) && comp->z < comp->imax)
			{
				comp->tmp1 = comp->z_r;
				comp->z_r = (comp->z_r * comp->z_r) - (comp->z_i * comp->z_i) + comp->c_r;
				comp->z_i = 2 * comp->z_i * comp->tmp1 + comp->c_i;
				++comp->z;
			}
			if (comp->z == comp->imax)
				put_pixel_to_image(env, x, y, GREEN);
			else
				put_pixel_to_image(env, x, y, ((comp->z * 700) / comp->imax));
			++y;
		}
		++x;
	}
}
