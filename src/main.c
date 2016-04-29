/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:49:42 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/29 18:22:40 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

t_move	init_shifting(void)
{
	t_move	mov;

	mov.shift.x = 0;
	mov.shift.y = 0;
	return(mov);
}

t_source	init_src(t_env *env, t_complex *comp, t_move *mov)
{
	t_source	src;

	src.env = env;
	src.comp = comp;
	src.mov = mov;
	return(src);
}

int		main(int ac, char **av)
{
	t_complex	*comp;
	t_env		*env;
	/*t_source	*src;*/

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
	comp->i = 0;
	comp->j = 0;
	env->comp = comp;
	env->init = 0;
	/*if (!env->img_ptr)*/
		/*mlx_destroy_image(env->mlx_ptr, env->img_ptr);*/
	draw_again(env);
	mlx_key_hook(env->win_ptr, key_commands, env);
	/*mlx_hook(env->win_ptr, 6, 0, key_commands, &env);*/
	mlx_loop(env->mlx_ptr);
	return (0);
}
