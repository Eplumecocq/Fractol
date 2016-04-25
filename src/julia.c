/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 10:32:58 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/25 18:09:45 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	color_julia(t_env *env, t_complex *comp)
{
	int		color;

	color = 0;
	if (comp->z_i > (0.04 + env->depth / 1000))
			color = BLUE + env->depth;
	else if (comp->z_i <= (0.04 + env->depth / 1000) 
			&& comp->z_i >= (-0.04 + env->depth / 1000))
			color = WHITE + env->depth;
	else if (comp->z_i < (-0.04 + env->depth / 1000))
			color = GREEN + env->depth;
	put_pixel_to_image(env, comp->x, comp->y, color / env->depth);
}

static void		draw_julia(t_env *env, t_complex *comp)
{
	while (comp->x++ < IMAGE_X - 1)
	{
		while (comp->y++ < IMAGE_Y - 1)
		{
			comp->c_r = 0.285;
			comp->c_i = 0.01;
			comp->z_r = comp->x1 + (comp->x2 - comp->x1) / IMAGE_X * comp->x;
			comp->z_i = comp->y1 + (comp->y2 - comp->y1) / IMAGE_Y * comp->y;
			while (comp->z < env->depth)
			{
				comp->tmp1 = comp->z_r;
				comp->z_r = comp->z_r * comp->z_r - comp->z_i * comp->z_i + comp->c_r;
				comp->z_i = 2 * comp->tmp1 * comp->z_i + comp->c_i;
				comp->z++;
			}
			comp->z = 0;
			if (comp->z_r * comp->z_r + comp->z_i + comp->z_i <= 4)
				color_julia(env, comp);
			else
				put_pixel_to_image(env, comp->x, comp->y, BLACK);
		}
		comp->y = 0;
	}
}

void			julia(t_env *env)
{
	t_complex *comp;

	comp = env->comp;
	if (env->init == 0)
	{
		env->depth = 45;
		comp->x1 = -1.6;
		comp->x2 = 1.6;
		comp->y1 = -1.4;
		comp->y2 = 1.4;
		env->init = 1;
		env->zoom = 10;
	}
	comp->x = 0;
	comp->y = 0;
	comp->z = 0;
	draw_julia(env, comp);
}
