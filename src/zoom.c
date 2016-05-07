/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 11:51:51 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/06 14:06:43 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"

void	zoom(t_env *env, int key_pressed, double *px, double *py)
{
	t_complex *comp;
	
	comp = env->comp;
	env->zoom = 10;
	if (key_pressed == KEY_ZOOM_U || key_pressed == 1 || key_pressed == 4)
	{
		*px = *px / 1.2;
		*py = *py / 1.2;
		comp->k *= 1.05;
		if (env->zoom % 3 == 0)
				++env->depth;
	}
	else
	{
		*px = *px * 1.2;
		*py = *py * 1.2;
		comp->k /= 1.05;
		if (env->zoom % 3 == 0)
				--env->depth;
	}
}

void	apply_zoom(t_env *env, int key_pressed, int x, int y)
{
	t_complex	*comp;
	double		px;
	double		py;
	double		x_cent;
	double		y_cent;

	(void)key_pressed;
	comp = env->comp;
	px = comp->x2 - comp->x1;
	py = comp->y2 - comp->y1;
	x_cent = comp->x1 + px / IMAGE_DX * (double)x;
	y_cent = comp->y1 + py / IMAGE_DY * (double)y;
	zoom(env, key_pressed, &px, &py);
	comp->x1 = x_cent - px / 2;
	comp->x2 = x_cent + px / 2;
	comp->y1 = y_cent - py / 2;
	comp->y2 = y_cent + py / 2;
	printf("x1 : %f\n", comp->x1);
	printf("x2 : %f\n", comp->x2);
	printf("y1 : %f\n", comp->y1);
	printf("y2 : %f\n", comp->y2);
	ft_putchar('\n');
}

void	go_deep(t_env *env, int key_pressed)
{
	if (KEY_DEPTH_U == key_pressed)
			env->comp->imax++;
	else
	{
		if (env->depth > 2)
				env->comp->imax--;
	}
}
