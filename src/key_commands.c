/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:12:42 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/26 16:48:54 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_reset(int key_pressed, t_env *env)
{
	if (key_pressed == KEY_RESET)
	{
		init_fractal(env);
		do_it_again(env);
		draw_fractal(env);
	}
}

void	key_change_iter(int key_pressed, t_env *env)
{
	if (key_pressed == KEY_ITEP)
	{
		env->itemax = env->itemax + 1;
		do_it_again(env);
		draw_fractal(env);
	}
	else if (key_pressed == KEY_ITEM)
	{
		env->itemax = env->itemax - 1;
		if (env->itemax == 0)
			env->itemax += 1;
		do_it_again(env);
		draw_fractal(env);
	}
}

int		key_commands(int key_pressed, t_env *env)
{
	key_reset(key_pressed, env);
	shifting_x(key_pressed, env);
	shifting_y(key_pressed, env);
	switch_fractal(key_pressed, env);
	switch_fractal_bis(key_pressed, env);
	key_change_iter(key_pressed, env);
	if (key_pressed == KEY_ESC)
		exit(0);
	if (key_pressed == KEY_O)
		env->on = !(env->on);
	if (key_pressed == KEY_M)
	{
		if (env->menu == 0)
			window_menu(env);
		else
		{
			do_it_again(env);
			draw_fractal(env);
			env->menu = 0;
		}
	}
	return (0);
}

int		motion_commands(int x, int y, t_env *env)
{
	if ((env->type == JULIA || env->type == GLYNN) && env->on)
	{
		env->c_r = (double)(x - 300) / 100;
		env->c_i = (double)(y - 300) / 100;
		do_it_again(env);
		draw_fractal(env);
	}
	return (0);
}
