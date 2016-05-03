/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 12:23:59 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/29 13:50:24 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		motion_commands(int x, int y, t_env *env)
{
	t_complex *comp;

	comp = env->comp;
	if (x >= 0 && y >= 0 && x <= IMAGE_X && y <= IMAGE_Y && env->co)
	{
		env->comp->c_r = -1 + 2 / (double)IMAGE_X * (double)x;
		env->comp->c_i = -1 + 2 / (double)IMAGE_Y * (double)y;
		draw_again(env);
	}
	return (0);
}

int		mouse_commands(int key_pressed, int x, int y, t_env *env)
{
	if ((key_pressed == 1 || key_pressed == 2 || key_pressed == 4 
							|| key_pressed == 5) && x >= 0 && y >= 0)
		apply_zoom(env, key_pressed, x, y);
	draw_again(env);
	return (0);
}

int		key_commands(int key_pressed, t_env *env)
{
	if (key_pressed == KEY_UP || key_pressed == KEY_DOWN 
			|| key_pressed == KEY_LEFT || key_pressed == KEY_RIGHT)
		key_shifting(env, key_pressed);
	if (key_pressed == KEY_RESET)
		key_reset(env);
	if (key_pressed == KEY_ESC)
		exit(0);
	if (key_pressed == KEY_DEPTH_U || key_pressed == KEY_DEPTH_D)
			go_deep(env, key_pressed);
	if (key_pressed == KEY_ZOOM_U || key_pressed == KEY_ZOOM_D)
			apply_zoom(env, key_pressed, 400, 300);
	if (key_pressed == KEY_C)
			env->co = !(env->co);
	draw_again(env);
	return(0);
}


