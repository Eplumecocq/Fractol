/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:59:57 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/20 18:38:10 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	color_mandelbrot(t_env *env, t_complex *comp)
{
	int		color;

	color = 0;
	if (comp->z_i > (4 + env->depth / 1000))
			color = BLUE + env->comp->z / env->depth;
	else if (comp->z_i <= (4 + env->depth / 100) 
					&& comp->z_i >= (-4 + env->depth / 100))
			color = WHITE + env->comp->z / env->depth;
	else if (comp->z_i < (-4 + env->depth / 1000))
			color = GREEN + env->comp->z / env->depth;
	put_pixel_to_image(env, comp->x, comp->y, color);
}

void	draw_mandelbrot(t_env *env, t_complex *comp)
{
	while (comp->x++ < IMAGE_X - 1)
	{
		while (comp->y++ < IMAGE_Y - 1)
		{
			comp->c_r = comp->x1 + (comp->x2 - comp->x1) / IMAGE_X * comp->x;
			comp->c_i = comp->y1 + (comp->y2 - comp->y1) / IMAGE_Y * comp->y;
			comp->z_r = 0;
			comp->z_i = 0;
			while (comp->z < env->depth)
			{
				comp->tmp1 = comp->z_r;
				comp->tmp2 = comp->z_i;
				comp->z_r = comp->tmp1 * comp->tmp1 - comp->tmp2 
						* comp->tmp2 + comp->c_r;
				comp->z_i = 2 * comp->tmp1 * comp->tmp2 + comp->c_i;
				comp->z++;
			}
			comp->z = 0;
			if (comp->z_r * comp->z_r + comp->z_i + comp->z_i > 4)
					color_mandelbrot(env, comp);
			else
					put_pixel_to_image(env, comp->x, comp->y, BLACK);
		}
		comp->y = 0;
	}
}

void	mandelbrot(t_env *env)
{
	t_complex	*comp;

	comp = env->comp;
	if (env->init == 0)
	{
		env->depth = 25;
		comp->x1 = -2.1;
		comp->x2 = 0.6;
		comp->y1 = -1.2;
		comp->y2 = 1.2;
		env->init = 1;
		env->zoom = 10;
	}
	comp->x = 0;
	comp->y = 0;
	comp->z = 0;
	draw_mandelbrot(env, comp);
}
