/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glynn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:18:29 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/24 18:44:20 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int		init_glynn(t_env *env)
{
	env->z_r = (env->x * (env->x2 - env->x1) / IMAGE_X) + env->x1;
	env->z_i = (env->y * (env->y2 - env->y1) / IMAGE_Y) + env->y1;
	return(0);
}

void	draw_glynn(t_env *env)
{
	int		nb_iter;

	env->x = 0;
	while (env->x++ < IMAGE_X)
	{
		env->y = 0;
		while (env->y++ < IMAGE_Y)
		{
			nb_iter = init_glynn(env);
			while (nb_iter++ < env->itemax && env->z_r * env->z_r + env->z_i * env->z_i < 4)
			{
				env->tmp = env->z_r;
				env->z_r = sqrt((env->z_r * env->z_r - env->z_i * env->z_i) * (env->z_r * env->z_r - env->z_i * env->z_i)) + env->c_r;
				env->z_i = sqrt((2 * env->tmp * env->z_i) * (env->z_i * env->tmp * 2)) + env->c_i;
			}
			if (nb_iter == env->itemax)
				put_pixel(env, 0, 0, 0);
			else
				put_pixel(env, (nb_iter * 700 / env->itemax - env->r), 0, 0);
				/*put_pixel(env, nb_iter * 200 / env->itemax - env->r - 200, nb_iter * 200 / env->itemax - env->g - 200, nb_iter * 200 / env->itemax - env->b - 200);*/
		}
	}
}

t_env	glynn(t_env *env)
{
	env->c_r = 0.291;
	env->c_i = 0.006;
	env->x1 = -1.0;
	env->x2 = 1.0;
	env->y1 = -1.0;
	env->y2 = 1.0;
	env->itemax = 200;
	/*env->r = RED;*/
	/*env->g = GREEN;*/
	/*env->b = BLUE;*/
	return(*env);
}
