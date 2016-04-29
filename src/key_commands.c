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

int		key_commands(int key_pressed, t_env *env)
{
	if (key_pressed == KEY_UP || key_pressed == KEY_DOWN 
			|| key_pressed == KEY_LEFT || key_pressed == KEY_RIGHT)
		key_shifting(env, key_pressed);
	if (key_pressed == KEY_RESET)
		key_reset(env);
	if (key_pressed == KEY_ESC)
		exit(0);
	draw_again(env);
	return(0);
}
