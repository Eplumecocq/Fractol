/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:51:51 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/04 15:16:48 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		key_shifting(t_env *env, int key_pressed)
{
	env->init = 1;
	t_complex	*comp;

	comp = env->comp;
	if (key_pressed == KEY_UP)
	{
		++comp->j;
		comp->coeff1 = comp->j * STEP;
	}
	if (key_pressed == KEY_DOWN)
	{
		--comp->j;
		comp->coeff1 = comp->j * STEP;
	}
	if (key_pressed == KEY_LEFT)
	{
		++comp->i;
		comp->coeff2 = comp->i * STEP;
	}
	if (key_pressed == KEY_RIGHT)
	{
		--comp->i;
		comp->coeff2 = comp->i * STEP;
	}
}

void	key_reset(t_env *env)
{
	t_complex	*comp;

	comp = env->comp;

	ft_bzero(env->addr, IMAGE_X * IMAGE_Y);
	comp->x1 -= comp->coeff1;
	comp->x2 -= comp->coeff1;
	comp->y1 -= comp->coeff2;
	comp->y2 -= comp->coeff2;
	comp->coeff1 = 0;
	comp->coeff2 = 0;
	comp->i = 0;
	comp->j = 0;
	draw_again(env);
}

void	reset_all(t_env *env)
{
	t_complex *comp;

	comp = env->comp;

	if (env->init == 1)
	{
		env->init = 0;
		draw_again(env);
	}
}
