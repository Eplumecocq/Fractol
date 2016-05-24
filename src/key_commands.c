/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:12:42 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/24 18:44:09 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_reset(int key_pressed, t_env *env)
{
	if (key_pressed == KEY_RESET)
	{
		init_fractal(env);
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
		env->img.img_ptr = mlx_new_image(env->mlx_ptr, IMAGE_X, IMAGE_Y);
		env->img.addr = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);
		draw_fractal(env);
	}
}

void	key_change_iter(int key_pressed, t_env *env)
{
	if (key_pressed == KEY_ITEP)
	{
		env->itemax = env->itemax + 1;
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
		env->img.img_ptr = mlx_new_image(env->mlx_ptr, IMAGE_X, IMAGE_Y);
		env->img.addr = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);
		draw_fractal(env);
	}
	else if (key_pressed == KEY_ITEM)
	{
		env->itemax = env->itemax - 1;
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
		env->img.img_ptr = mlx_new_image(env->mlx_ptr, IMAGE_X, IMAGE_Y);
		env->img.addr = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);
		draw_fractal(env);
	}
}

/*void	key_change_color(int key_pressed, t_env *env)*/
/*{*/
	/*if (key_pressed == KEY_C)*/
	/*{*/
		/*env->b += 35;*/
		/*[>env->g += 22;<]*/
		/*[>env->b += 10;<]*/
		/*ft_putstr("color bug");*/
		/*mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);*/
		/*env->img.img_ptr = mlx_new_image(env->mlx_ptr, IMAGE_X, IMAGE_Y);*/
		/*env->img.addr = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);*/
		/*draw_fractal(env);*/
	/*}*/
/*}*/

int		key_commands(int key_pressed, t_env *env)
{
	key_reset(key_pressed, env);
	shifting_x(key_pressed, env);
	shifting_y(key_pressed, env);
	switch_fractal(key_pressed, env);
	key_change_iter(key_pressed, env);
	/*key_change_color(key_pressed, env);*/
	if (key_pressed == KEY_ESC)
		exit(0);
	if (key_pressed == KEY_O)
		env->on = !(env->on);
	return (0);
}

int		motion_commands(int x, int y, t_env *env)
{
	if ((env->type == JULIA || env->type == GLYNN) && env->on)
	{
		env->c_r = -1 + 2 / IMAGE_DX * (double)x;
		env->c_i = -1 + 2 / IMAGE_DY * (double)y;
		/*env->c_r = (double)(x - 300) / 100;*/
		/*env->c_i = (double)(y - 300) / 100;*/
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
		env->img.img_ptr = mlx_new_image(env->mlx_ptr, IMAGE_X, IMAGE_Y);
		env->img.addr = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);
		draw_fractal(env);
	}
	return (0);
}
