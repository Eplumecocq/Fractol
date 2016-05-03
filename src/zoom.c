/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 11:51:51 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/02 14:05:18 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_env *env, int key_pressed, double *diffx, double *diffy)
{
	if (key_pressed == KEY_ZOOM_U || key_pressed == 1 || key_pressed == 4)
	{
		*diffx = *diffx / 1.2;
		*diffy = *diffy / 1.2;
		env->zoom += 1;
		if (env->zoom % 3 == 0)
				++env->depth;
	}
	else
	{
		*diffx = *diffx * 1.2;
		*diffy = *diffy * 1.2;
		env->zoom -= 1;
		if (env->zoom % 3 == 0)
				--env->depth;
	}
}

void	apply_zoom(t_env * env, int key_pressed, int x, int y)
{
	t_complex	*comp;
	double		diffx;
	double		diffy;
	double		x_cent;
	double		y_cent;

	comp = env->comp;
	diffx = comp->x2 - comp->x1;
	diffy = comp->y2 - comp->y1;
	x_cent = comp->x1 + diffx / (double)IMAGE_X * (double)x;
	y_cent = comp->y1 + diffy / (double)IMAGE_Y * (double)y;
	zoom(env, key_pressed, &diffx, &diffy);
	comp->x1 = x_cent - diffx / 2;
	comp->x2 = x_cent + diffx / 2;
	comp->y1 = y_cent - diffy / 2;
	comp->y2 = y_cent + diffy / 2;
}

void	go_deep(t_env *env, int key_pressed)
{
	if (KEY_DEPTH_U == key_pressed)
			env->depth++;
	else
	{
		if (env->depth > 2)
				env->depth--;
	}
}
