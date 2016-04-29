/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:51:51 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/29 14:05:18 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		key_shifting(t_env *env, int key_pressed)
{
	t_complex	*comp;

	comp = env->comp;
	if (key_pressed == KEY_UP)
	{
		comp->y1 += STEP;
		comp->y2 += STEP;
		++comp->i;
	}
	if (key_pressed == KEY_DOWN)
	{
		comp->y1 -= STEP;
		comp->y2 -= STEP;
		--comp->i;
	}
	if (key_pressed == KEY_LEFT)
	{
		comp->x1 += STEP;
		comp->x2 += STEP;
		++comp->j;
	}
	if (key_pressed == KEY_RIGHT)
	{
		comp->x1 -= STEP;
		comp->x2 -= STEP;
		--comp->j;
	}
}

void	key_reset(t_env *env)
{
	t_complex	*comp;

	comp = env->comp;

	ft_bzero(env->addr, IMAGE_X * IMAGE_Y);
	comp->x1 = comp->x1 - (comp->j * STEP) ;
	comp->x2 = comp->x2 - (comp->j * STEP) ;
	comp->y1 = comp->y1 - (comp->i * STEP) ;
	comp->y2 = comp->y2 - (comp->i * STEP) ;
	comp->i = 0;
	comp->j = 0;
	draw_again(env);
}
