/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:17:23 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/24 18:27:03 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			init_juju(t_env *env)
{
	env->z_r = (env->x * (env->x2 - env->x1) / IMAGE_X) + env->x1;
	env->z_i = (env->y * (env->y2 - env->y1) / IMAGE_Y) + env->y1;
	return (0);
}

void		draw_julia(t_env *env)
{
	int		nb_iter;
	
	env->x = 0;
	while (++env->x < IMAGE_X)
	{
		env->y = 0;
		while (++env->y < IMAGE_Y)
		{
			nb_iter = init_juju(env);
			while (++nb_iter < env->itemax && 
					env->z_r * env->z_r + env->z_i * env->z_i < 4)
			{
				env->tmp = env->z_r;
				env->z_r = (env->z_r * env->z_r) - (env->z_i * env->z_i) + env->c_r;
				env->z_i = 2 * env->tmp * env->z_i + env->c_i;
			}
			if (nb_iter == env->itemax)
				put_pixel(env, BLACK, BLACK, BLACK);
			else
				put_pixel(env, (nb_iter * 500 / env->itemax), 0, 0);
				/*put_pixel(env, nb_iter * 200 / env->itemax - env->r - 200, nb_iter * 200 / env->itemax - env->g - 200, nb_iter * 200 / env->itemax - env->b - 200);*/
		}
	}
}

t_env		julia(t_env *env)
{
	env->c_r = 0.285;
	env->c_i = 0.01;
	env->x1 = -1;
	env->x2 = 1.2;
	env->y1 = -1.2;
	env->y2 = 1.2;
	/*env->r = BLACK;*/
	/*env->g = GREEN;*/
	/*env->b = BLUE;*/
	env->itemax = 120;
	return (*env);
}
