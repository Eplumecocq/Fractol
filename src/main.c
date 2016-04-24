/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:49:42 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/20 16:44:51 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"


void	draw_again(t_env *env)
{
	if (!env->img_ptr)
			mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	draw_frac(env);
}

int		close_win(int keycode, void *param)
{
	param = NULL;

	if (keycode == KEY_ESC)
			exit (-1);
	return (0);
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
	ft_putendl("debug");
	ft_putnbr(env->type);
	env->comp = comp;
	env->init = 0;
	draw_again(env);
	mlx_key_hook(env->win_ptr, close_win, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
