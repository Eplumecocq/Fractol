/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:15:34 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/24 15:15:53 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_env *env, int r, int g, int b)
{
	env->img.addr[env->y * env->img.size_line + env->x * env->img.bpp / 8 + 2] = r;
	env->img.addr[env->y * env->img.size_line + env->x * env->img.bpp / 8 + 1] = g;
	env->img.addr[env->y * env->img.size_line + env->x * env->img.bpp / 8] = b;
}

void	put_pixel_to_image(t_env *env, int x, int y, int color)
{
	int	i;

	if (env->img.endian == 0)
	{
		i = (env->img.size_line * y) + (x * (env->img.bpp / 8));
		env->img.addr[i] = mlx_get_color_value(env->mlx_ptr, color);
		env->img.addr[i + 1] = mlx_get_color_value(env->mlx_ptr, color >> 8);
		env->img.addr[i + 2] = mlx_get_color_value(env->mlx_ptr, color >> 16);
	}
	else
	{
		i = (env->img.size_line * y) + (x * (env->img.bpp / 8));
		env->img.addr[i] = mlx_get_color_value(env->mlx_ptr, color >> 16);
		env->img.addr[i + 1] = mlx_get_color_value(env->mlx_ptr, color >> 8);
		env->img.addr[i + 2] = mlx_get_color_value(env->mlx_ptr, color);
	}
}

int		draw_fractal(t_env *env)
{
	if (env->type == MANDELBROT)
	{
		draw_mandelbrot(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
	}
	else if (env->type == JULIA)
	{
		draw_julia(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
	}	
	else if (env->type == GLYNN)
	{
		draw_glynn(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
	}	
	return(0);
}
