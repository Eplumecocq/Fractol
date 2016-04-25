/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 17:49:42 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/25 15:31:07 by eplumeco         ###   ########.fr       */
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

/*void	put_pixel_to_image(t_env *env, int x, int y, int color)*/
/*{*/
/*int		r;*/
/*int		g;*/
/*int		b;*/
/*int		i;*/

/*r = (color >> 16) & 0xFF;*/
/*g = (color >> 8 ) & 0xFF;*/
/*b = (color >> 0) & 0xFF;*/
/*i = x * 4 + y * env->size_line;*/
/*env->addr[i] = b;*/
/*env->addr[i + 1] = g;*/
/*env->addr[i + 2] = r;*/
/*env->addr[i + 3] = 1;*/
/*}*/

void	draw_frac(t_env *env)
{

		if (env->type == MANDELBROT)
		{
				mandelbrot(env);
				mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
		}
		else if (env->type == JULIA)
		{
			julia(env);
			mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
		}
}
