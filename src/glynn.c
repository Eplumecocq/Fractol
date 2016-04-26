/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glynn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 18:05:33 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/26 18:58:15 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static void		color_glynn(t_env *env, t_complex *comp)
{
	int		color;

	color = 0;
	if (comp->z_i > (4 + env->depth / 1000))
		color = BLUE + env->comp->z / env->depth;
	else if (comp->z_i <= (4 + env->depth / 1000) 
			&& comp->z_i >= (-4 + env->depth / 1000))
		color = WHITE + env->comp->z / env->depth;
	else if (comp->z_i < (-4 + env->depth / 1000))
		color = GREEN + env->comp->z / env->depth;
	put_pixel_to_image(env, comp->x, comp->y, color);
}

void		draw_glynn(t_env *env, t_complex *comp)
{
	while (comp->x++ < IMAGE_X)
	{
		while (comp->y++ < IMAGE_Y)
		{
			comp->z_r = comp->x1 + (comp->x2 - comp->x1) / IMAGE_X * comp->x;
			comp->z_i = comp->y1 + (comp->y2 - comp->y1) / IMAGE_Y * comp->y;
			while (comp->z < env->depth)
			{
				comp->tmp1 = comp->z_r;
				comp->z_r = sqrt((comp->z_r * comp->z_r - comp->z_i * comp->z_i) 
						* (comp->z_r * comp->z_r - comp->z_i * comp->z_i) + comp->c_r);
				comp->z_i = sqrt((2 * comp->tmp1 * comp->z_i) * (2 * comp->tmp1 * comp->z_i) + comp->c_i);
				comp->z++;
			}
			comp->z = 0;
			if (sqrt(comp->z_r * comp->z_r + comp->z_i * comp->z_i) < 4)
				color_glynn(env, comp);
			else
				put_pixel_to_image(env, comp->x, comp->y, WHITE);	
		}
	}
}

void		glynn(t_env *env)
{
	t_complex *comp;

	comp = env->comp;
	if (env->init == 0)
	{
		comp->c_r = 0.291;
		comp->c_i = 0.006;
		env->depth = 25;
		comp->x1 = -1;
		comp->x2 = 1;
		comp->y1 = -1;
		comp->y2 = 1;
		env->init = 1;
		env->zoom = 10;
	}
	comp->x = 0;
	comp->y = 0;
	comp->z = 0;
	draw_glynn(env, comp);
}
