/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 16:19:57 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/26 11:42:21 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int key_pressed, int x, int y, t_env *env)
{
	env->zoom_x = (x * (env->x2 - env->x1) / IMAGE_DX + env->x1);
	env->zoom_y = (y * (env->y2 - env->y1) / IMAGE_DY + env->y1);
	if (key_pressed == WHEEL_ZOOM_D)
	{
		env->x1 = env->zoom_x + (env->x1 - env->zoom_x) * 1.05;
		env->x2 = env->zoom_x + (env->x2 - env->zoom_x) * 1.05;
		env->y1 = env->zoom_y + (env->y1 - env->zoom_y) * 1.05;
		env->y2 = env->zoom_y + (env->y2 - env->zoom_y) * 1.05;
		do_it_again(env);
		draw_fractal(env);
	}
	else if (key_pressed == WHEEL_ZOOM_U)
	{
		env->x1 = env->zoom_x + (env->x1 - env->zoom_x) / 1.05;
		env->x2 = env->zoom_x + (env->x2 - env->zoom_x) / 1.05;
		env->y1 = env->zoom_y + (env->y1 - env->zoom_y) / 1.05;
		env->y2 = env->zoom_y + (env->y2 - env->zoom_y) / 1.05;
		do_it_again(env);
		draw_fractal(env);
	}
}

int		mouse_commands(int key_pressed, int x, int y, t_env *env)
{
	zoom(key_pressed, x, y, env);
	return (0);
}
