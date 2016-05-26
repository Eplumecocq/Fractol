/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:32:07 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/26 11:40:23 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shifting_y(int key_pressed, t_env *env)
{
	if (key_pressed == KEY_UP)
	{
		env->y1 += (env->y2 - env->y1) / IMAGE_Y * 10;
		env->y2 += (env->x2 - env->x1) / IMAGE_Y * 10;
		do_it_again(env);
		draw_fractal(env);
	}
	else if (key_pressed == KEY_DOWN)
	{
		env->y1 -= (env->y2 - env->y1) / IMAGE_Y * 10;
		env->y2 -= (env->x2 - env->x1) / IMAGE_Y * 10;
		do_it_again(env);
		draw_fractal(env);
	}
}

void	shifting_x(int key_pressed, t_env *env)
{
	if (key_pressed == KEY_LEFT)
	{
		env->x1 += (env->x2 - env->x1) / IMAGE_X * 10;
		env->x2 += (env->x2 - env->x1) / IMAGE_X * 10;
		do_it_again(env);
		draw_fractal(env);
	}
	if (key_pressed == KEY_RIGHT)
	{
		env->x1 -= (env->x2 - env->x1) / IMAGE_X * 10;
		env->x2 -= (env->x2 - env->x1) / IMAGE_X * 10;
		do_it_again(env);
		draw_fractal(env);
	}
}
