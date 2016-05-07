/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 18:23:58 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/07 15:59:38 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static void		init_mandel(t_complex *comp, t_env *env)
{
	comp->x1 = -2.1  / comp->k + comp->coeff2;
	comp->x2 = 0.6 / comp->k + comp->coeff2;
	comp->y1 = -1.2 / comp->k + comp->coeff1;
	comp->y2 = 1.2 / comp->k + comp->coeff1;
	comp->zoom_x = IMAGE_X / (comp->x2 - comp->x1);
	comp->zoom_y = IMAGE_Y / (comp->y2 - comp->y1);
	comp->imax = 50;
	env->init = 0;
}

static void		init_coco(t_complex *comp, int x, int y)
{
	comp->c_r = x / comp->zoom_x + comp->x1;
	comp->c_i = y / comp->zoom_y + comp->y1;
	comp->z_r = 0;
	comp->z_i = 0;
}

void	mandelbrot(t_env *env)
{
	t_complex *comp;

	comp = env->comp;
	int		y;
	int		x;
	
	x = 0;
	init_mandel(comp, env);
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
				put_pixel_to_image(env, x, y, BLACK);
			else
				put_pixel_to_image(env, x, y, ((comp->z * 500) / comp->imax));
			++y;
		}
		++x;
	}
}
