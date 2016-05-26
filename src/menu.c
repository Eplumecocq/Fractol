/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 12:16:54 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/26 16:53:40 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	window_menu(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 50, WHITE, "Press 1 - 3 to"
			" change fractal");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 75, WHITE, "Press 'O' to"
			" enable C parameters changes,");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 90, WHITE, "and press 'O'"
			" again to save new visual");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 115, WHITE, "Press arrow"
			" keys to move");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 135, WHITE, "Press +/- to"
			" change iteration's number");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 155, WHITE, "Press 'R' to"
			" reset");
	env->menu = 1;
}

void	permanent_menu(t_env *env)
{
	if (env->type == MANDELBROT)
		mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 10, WHITE, "The current"
				" run is Mandelbrot");
	else if (env->type == JULIA)
		mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 10, WHITE, "The current"
				" run is Julia");
	else if (env->type == GLYNN)
		mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 10, WHITE, "The current"
				" run is Glynn");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 500, 10, WHITE, "Number of"
			" iterations : ");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 730, 10, WHITE,
			ft_itoa(env->itemax));
	if (env->itemax == 1)
		mlx_string_put(env->mlx_ptr, env->win_ptr, 500, 50, WHITE, "Hey, it's"
				" already the minimum");
}
