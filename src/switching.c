/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:33:10 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/26 15:03:55 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	switch_fractal(int key_pressed, t_env *env)
{
	if (key_pressed == KEY_FRAC_1)
	{
		if (env->type != MANDELBROT)
		{
			env->type = MANDELBROT;
			init_fractal(env);
		}
		do_it_again(env);
		draw_fractal(env);
	}
	else if (key_pressed == KEY_FRAC_2)
	{
		if (env->type != JULIA)
		{
			env->type = JULIA;
			init_fractal(env);
		}
		do_it_again(env);
		draw_fractal(env);
	}
}

void	switch_fractal_bis(int key_pressed, t_env *env)
{
	if (key_pressed == KEY_FRAC_3)
	{
		if (env->type != GLYNN)
		{
			env->type = GLYNN;
			init_fractal(env);
		}
		do_it_again(env);
		draw_fractal(env);
	}
}
