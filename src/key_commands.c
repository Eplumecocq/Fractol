/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 12:23:59 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/07 15:34:48 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"

int		motion_commands(int x, int y, t_env *env)
{
	t_complex *comp;

	comp = env->comp;
	if (x >= 0 && y >= 0 && x <= IMAGE_X && y <= IMAGE_Y && env->on)
	{
		if (env->type == JULIA)
		{
			env->comp->jc_r = -1 + 2 / IMAGE_DX * (double)x;
			env->comp->jc_i = -1 + 2 / IMAGE_DY * (double)y;
			draw_again(env);
		}
		else if (env->type == GLYNN)
		{
			env->comp->gc_r = -1 + 2 / IMAGE_DX * (double)x;
			env->comp->gc_i = -1 + 2 / IMAGE_DY * (double)y;
			draw_again(env);
		}
	}
	/*if (x >= 0 && y >= 0 && x <= IMAGE_X && y <= IMAGE_Y && env->on)*/
	/*{*/
		/*env->comp->z_r = -1 + 2 / IMAGE_DX * (double)x;*/
		/*env->comp->z_i = -1 + 2 / IMAGE_DY * (double)y;*/
		/*draw_again(env);*/
	/*}*/
	return (0);
}

int		mouse_commands(int key_pressed, int x, int y, t_env *env)
{

	(void)env;
	if ((key_pressed == 5) && x >= 0 && y >= 0)
		apply_zoom(env, key_pressed, x, y);
	if (key_pressed == 4)
		apply_zoom(env, key_pressed, x, y);
	draw_again(env);
	return (0);
}

int		key_commands(int key_pressed, t_env *env)
{
	if (key_pressed == KEY_UP || key_pressed == KEY_DOWN 
			|| key_pressed == KEY_LEFT || key_pressed == KEY_RIGHT)
	{
		ft_putstr("shit=ft");
		key_shifting(env, key_pressed);
	}
	if (key_pressed == KEY_RESET)
		key_reset(env);
	if (key_pressed == ((MLX_MOD_SHIFT) * KEY_RESET))
		reset_all(env);
	if (key_pressed == KEY_ESC)
		exit(0);
	if (key_pressed == KEY_DEPTH_U || key_pressed == KEY_DEPTH_D)
			go_deep(env, key_pressed);
	/*if (key_pressed == KEY_ZOOM_U || key_pressed == KEY_ZOOM_D)*/
			/*apply_zoom(env, key_pressed, x, y);*/
	if (key_pressed == KEY_O)
			env->on = !(env->on);
	draw_again(env);
	return(0);
}


