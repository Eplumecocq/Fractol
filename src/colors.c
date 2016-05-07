/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:14:43 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/03 18:14:43 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_mandelbrot(t_env *env, t_complex *comp)
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

void	color_julia(t_env *env, t_complex *comp)
{
	int		color;

	color = 0;
	if (comp->z_i > (0.04 + env->depth / 1000))
			color = BLUE + env->depth;
	else if (comp->z_i <= (0.04 + env->depth / 1000) 
			&& comp->z_i >= (-0.04 + env->depth / 1000))
			color = YELLOW + env->depth;
	else if (comp->z_i < (-0.04 + env->depth / 1000))
			color = GREEN + env->depth;
	put_pixel_to_image(env, comp->x, comp->y, color);
}

void	color_business(t_env *env, t_complex *comp)
{
	int		color;

	color = 0;
	if (comp->z_i > (0.04 + env->depth / 1000))
			color = BLUE + env->depth;
	else if (comp->z_i <= (0.04 + env->depth / 1000) 
			&& comp->z_i >= (-0.04 + env->depth / 1000))
			color = WHITE + env->depth;
	else if (comp->z_i < (-0.04 + env->depth / 1000))
			color = YELLOW + env->depth;
	put_pixel_to_image(env, comp->x, comp->y, color);
}
