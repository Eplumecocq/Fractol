/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:15:34 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/26 14:36:51 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_env *env, int r, int g, int b)
{
	env->img.addr[env->y * env->img.size_line + env->x
		* env->img.bpp / 8 + 2] = r;
	env->img.addr[env->y * env->img.size_line + env->x
		* env->img.bpp / 8 + 1] = g;
	env->img.addr[env->y * env->img.size_line + env->x * env->img.bpp / 8] = b;
}

int		draw_fractal(t_env *env)
{
	if (env->type == MANDELBROT)
	{
		draw_mandelbrot(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr,
				env->img.img_ptr, 0, 0);
	}
	else if (env->type == JULIA)
	{
		draw_julia(env);
		mlx_put_image_to_window(env->mlx_ptr,
				env->win_ptr, env->img.img_ptr, 0, 0);
	}
	else if (env->type == GLYNN)
	{
		draw_glynn(env);
		mlx_put_image_to_window(env->mlx_ptr,
				env->win_ptr, env->img.img_ptr, 0, 0);
	}
	permanent_menu(env);
	return (0);
}

t_env	do_it_again(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
	env->img.img_ptr = mlx_new_image(env->mlx_ptr, IMAGE_X, IMAGE_Y);
	env->img.addr = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp,
			&env->img.size_line, &env->img.endian);
	return (*env);
}
