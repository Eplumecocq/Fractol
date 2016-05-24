/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:32:07 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/24 13:55:00 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shifting_y(int key_pressed, t_env *env)
{
	if (key_pressed == KEY_UP)
	{
		env->y1 += (env->y2 - env->y1) / IMAGE_Y * 10;
		env->y2 += (env->x2 - env->x1) / IMAGE_Y * 10;
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
		env->img.img_ptr = mlx_new_image(env->mlx_ptr, IMAGE_X, IMAGE_Y);
		env->img.addr = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);
		draw_fractal(env);
	}
	else if (key_pressed == KEY_DOWN)
	{
		env->y1 -= (env->y2 - env->y1) / IMAGE_Y * 10;
		env->y2 -= (env->x2 - env->x1) / IMAGE_Y * 10;
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
		env->img.img_ptr = mlx_new_image(env->mlx_ptr, IMAGE_X, IMAGE_Y);
		env->img.addr = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);
		draw_fractal(env);
	}
}

void	shifting_x(int key_pressed, t_env *env)
{
	if (key_pressed == KEY_LEFT)
	{
		env->x1 += (env->x2 - env->x1) / IMAGE_X * 10;
		env->x2 += (env->x2 - env->x1) / IMAGE_X * 10;
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
		env->img.img_ptr = mlx_new_image(env->mlx_ptr, IMAGE_X, IMAGE_Y);
		env->img.addr = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);
		draw_fractal(env);
	}
	if (key_pressed == KEY_RIGHT)
	{
		env->x1 -= (env->x2 - env->x1) / IMAGE_X * 10;
		env->x2 -= (env->x2 - env->x1) / IMAGE_X * 10;
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
		env->img.img_ptr = mlx_new_image(env->mlx_ptr, IMAGE_X, IMAGE_Y);
		env->img.addr = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);
		draw_fractal(env);
	}
}

/*void	reset_all(t_env *env)*/
/*{*/
	/*t_complex *comp;*/

	/*comp = env->comp;*/

	/*if (env->init == 1)*/
	/*{*/
		/*env->init = 0;*/
		/*draw_again(env);*/
	/*}*/
/*}*/
