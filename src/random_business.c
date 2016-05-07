/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_business.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:34:08 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/03 14:15:58 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static void	draw_business(t_env *env, t_complex *comp)
{
	while (comp->y++ < IMAGE_Y - 1)
	{
		while (comp->x++ < IMAGE_X - 1)
		{
			comp->z_r = comp->x1 + (comp->x2 - comp->x1) / IMAGE_X * comp->x;
			comp->z_i = comp->y1 + (comp->y2 - comp->y1) / IMAGE_Y *comp->y;
			while (comp->z_r * comp->z_r + comp->z_i * comp->z_i <= 4 && comp->z < env->depth)
			{
				comp->tmp1 = comp->z_r;
				comp->z_r = comp->z_r * comp->z_r - comp->z_i * comp->z_i + comp->c_r;
				comp->z_i = 2 * comp->tmp1 * comp->z_i + comp->c_i;
				comp->z++;
			}
			comp->z = 0;
			if (comp->z_r * comp->z_r + comp->z_i * comp->z_i <= 4)
				put_pixel_to_image(env, comp->x, comp->y, BLACK);
			else
				color_business(env, comp);
		}
		comp->x = 0;
	}
}

void	random_business(t_env *env)
{
	t_complex *comp;

	comp = env->comp;
	if (env->init == 0)
	{
		comp->c_r = -1.268;
		comp->c_i = 0.003;
		comp->x1 = -1.6;
		comp->x2 = 1.6;
		comp->y1 = -1.4;
		comp->y2 = 1.4;
		env->init = 1;
		env->zoom = 10;
		env->depth = 30;
	}
	comp->y = 0;
	comp->x = 0;
	comp->z = 0;
	draw_business(env, comp);
}
