/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:49:42 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/07 16:29:51 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

t_source	init_src(t_env *env, t_complex *comp) 
{
	t_source	src;

	src.env = env;
	src.comp = comp;
	return(src);
}

t_complex	init_tmp(t_complex *comp)
{
	comp->jc_r = 0.285;
	comp->jc_i = 0.01;
	comp->gc_r = 0.291;
	comp->gc_i = 0.002;
	return (*comp);
}

int		main(int ac, char **av)
{
	t_complex	*comp;
	t_env		*env;

	if ((env = (t_env *)ft_memalloc(sizeof(t_env))) == NULL)
			ft_putendl("malloc failed");
	if ((comp = (t_complex *)ft_memalloc(sizeof(t_complex))) == NULL)
			ft_putendl("malloc failed");
	check_fractal(av[1], ac, env);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, IMAGE_X, IMAGE_Y, "Fractol");
	env->img_ptr = mlx_new_image(env->mlx_ptr, IMAGE_X, IMAGE_Y);
	env->addr = mlx_get_data_addr(env->img_ptr, &env->bpp, &env->size_line,
					&env->endian);
	comp->coeff1 = 0;
	comp->coeff2 = 0;
	comp->i = 0;
	comp->j = 0;
	comp->k = 1;
	env->comp = comp;
	init_tmp(comp);
	env->init = 0;
	env->on = 0;
	draw_again(env);
	mlx_mouse_hook(env->win_ptr, mouse_commands, env);
	mlx_hook(env->win_ptr, 2, 0, key_commands, env);
	mlx_hook(env->win_ptr, 6, (1L << 5), motion_commands, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
