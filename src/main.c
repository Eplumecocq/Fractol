/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:56:25 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/24 17:40:33 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

t_env	init_fractal(t_env *env)
{
	if (env->type == MANDELBROT)
		mandelbrot(env);
	if (env->type == JULIA)
		julia(env);
	if (env->type == GLYNN)
		glynn(env);
	return (*env);
}

int		main(int ac, char **av)
{
	t_env		*env;

	if ((env = (t_env *)ft_memalloc(sizeof(t_env))) == NULL)
		ft_putendl("Malloc gas failed");
	check_fractal(av[1], ac, env);
	init_fractal(env);
	env->on = 0;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, IMAGE_X, IMAGE_Y, "Fract'ol");
	env->img.img_ptr = mlx_new_image(env->mlx_ptr, IMAGE_X, IMAGE_Y);
	env->img.addr = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);
	mlx_expose_hook(env->win_ptr, draw_fractal, env);
	mlx_mouse_hook(env->win_ptr, mouse_commands, env);
	mlx_hook(env->win_ptr, 2, 0,  key_commands, env);
	mlx_hook(env->win_ptr, 6, (1L > 0), &motion_commands, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
