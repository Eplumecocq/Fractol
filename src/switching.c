/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:33:10 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/24 11:33:50 by eplumeco         ###   ########.fr       */
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
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
		env->img.img_ptr = mlx_new_image(env->mlx_ptr, IMAGE_X, IMAGE_Y);
		env->img.addr = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);
		draw_fractal(env);
	}
	else if (key_pressed == KEY_FRAC_2)
	{
		if (env->type != JULIA)
		{
			env->type = JULIA;
			init_fractal(env);
		}
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
		env->img.img_ptr = mlx_new_image(env->mlx_ptr, IMAGE_X, IMAGE_Y);
		env->img.addr = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);
		draw_fractal(env);
	}
	else if (key_pressed == KEY_FRAC_3)
	{
		if (env->type != GLYNN)
		{
			env->type = GLYNN;
			init_fractal(env);
		}
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
		env->img.img_ptr = mlx_new_image(env->mlx_ptr, IMAGE_X, IMAGE_Y);
		env->img.addr = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);
		draw_fractal(env);
	}
}
