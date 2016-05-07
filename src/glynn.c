/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glynn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 14:48:36 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/07 16:32:14 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static void		init_glynn(t_complex *comp, t_env *env)
{
	comp->x1 = -1.0 / comp->k + comp->coeff2;
	comp->x2 = 1.0 / comp->k + comp->coeff2;
	comp->y1 = -1.0 / comp->k + comp->coeff1;
	comp->y2 = 1.0 / comp->k + comp->coeff1;
	comp->imax = 50;
	env->init = 0;
}

static void		init_coco(t_complex *comp, int x, int y)
{
	comp->z_r = (x * (comp->x2 - comp->x1) / IMAGE_X) + comp->x1;
	comp->z_i = (y * (comp->y2 - comp->y1) / IMAGE_Y) + comp->y1;
	comp->c_r = comp->gc_r;
	comp->c_i = comp->gc_i;
}

void			glynn(t_env *env)
{
	t_complex	*comp;
	int			x;
	int			y;

	comp = env->comp;
	comp->z = 0;

	x = 0;
	init_glynn(comp, env);
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
				comp->z_r = sqrt((comp->z_r * comp->z_r - comp->z_i * comp->z_i) * (comp->z_r * comp->z_r - comp->z_i * comp->z_i)) + comp->c_r;
				comp->z_i = sqrt((2 * comp->z_i * comp->tmp1) * (2 * comp->z_i * comp->tmp1)) + comp->c_i;
				++comp->z;
			}
			if (comp->z == comp->imax)
				put_pixel_to_image(env, x, y, BLACK);
			else
				put_pixel_to_image(env, x, y, ((comp->z * 700) / comp->imax));
			++y;
		}
		++x;
	}
}
