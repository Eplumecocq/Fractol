/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:55:15 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/07 16:11:48 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_image(t_env *env, int x, int y, int color)
{
	int	i;

	if (env->endian == 0)
	{
		i = (env->size_line * y) + (x * (env->bpp / 8));
		env->addr[i] = mlx_get_color_value(env->mlx_ptr, color);
		env->addr[i + 1] = mlx_get_color_value(env->mlx_ptr, color >> 8);
		env->addr[i + 2] = mlx_get_color_value(env->mlx_ptr, color >> 16);
	}
	else
	{
		i = (env->size_line * y) + (x * (env->bpp / 8));
		env->addr[i] = mlx_get_color_value(env->mlx_ptr, color >> 16);
		env->addr[i + 1] = mlx_get_color_value(env->mlx_ptr, color >> 8);
		env->addr[i + 2] = mlx_get_color_value(env->mlx_ptr, color);
	}
}

void	draw_frac(t_env *env)
{

	if (env->type == MANDELBROT)
	{
		mandelbrot(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
		mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 10, WHITE, "The current run is Mandelbrot");
	}
	else if (env->type == JULIA)
	{
		julia2(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
		mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 10, WHITE, "The current run is Julia");
	}
	else if (env->type == RANDOM)
	{
		random_business(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
		mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 10, WHITE, "The current run is Random_business");
	}
	else if (env->type == GLYNN)
	{
		glynn(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
		mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 10, WHITE, "The current run is Glynn");	
	}
	else if (env->type == BURNING)
	{
		burning_ship(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
		mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 10, WHITE, "The current run is Burning_ship");	
	}
}

void	draw_again(t_env *env)
{
	if (!env->img_ptr)
		mlx_destroy_image(env->mlx_ptr, env->win_ptr);
	draw_frac(env);
}
