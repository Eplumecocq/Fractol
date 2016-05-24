/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:16:46 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/24 18:27:13 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_mandel(t_env *env)
{
	env->z_r = 0;
	env->z_i = 0;
	env->c_r = (env->x * (env->x2 - env->x1) / IMAGE_X) + env->x1;
	env->c_i = (env->y * (env->x2 - env->x1) / IMAGE_Y) + env->y1;
	return(0);
}

void	draw_mandelbrot(t_env *env)
{
	int		nb_iter;

	env->x = 0;
	while (++env->x < IMAGE_X)
	{
		env->y = 0;
		while (++env->y < IMAGE_Y)
		{
			nb_iter = init_mandel(env);
			while (++nb_iter < env->itemax && 
					env->z_r * env->z_r + env->z_i * env->z_i < 4)
			{
				env->tmp = env->z_r;
				env->z_r = (env->z_r * env->z_r) - (env->z_i * env->z_i) + env->c_r;
				env->z_i = env->z_i * env->tmp * 2 + env->c_i;
			}
			if (nb_iter == env->itemax)
				put_pixel(env, 0, 0, 0);
			else
				put_pixel(env, (nb_iter * 255 / env->itemax), 0, 0);
				/*put_pixel(env, nb_iter * 200 / env->itemax - env->r * 200, nb_iter * 200 / env->itemax - env->g * 200, nb_iter * 200 / env->itemax - env->b * 200);*/
		}
	}
}

t_env	mandelbrot(t_env *env)
{
	/*env->r = RED;*/
	/*env->g = GREEN;*/
	/*env->b = BLUE;*/
	env->x1 = -2.1;
	env->x2 = 0.6;
	env->y1 = -1.2;
	env->y2 = 1.2;
	env->itemax = 50;
	return(*env);
}
