/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:07:08 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/24 11:28:48 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void		put_error_usage(void)
{
	ft_putendl("\x1b[34;01m Usage : ./fractol [Mandelbrot] [Julia] [Glynn]\n");
	exit(0);
}

void	check_fractal(char *type, int ac, t_env *env)
{
	if (ac != 2)
		put_error_usage();
	if (ft_strcmp(type, "Mandelbrot") == 0)
		env->type = MANDELBROT;
	else if (ft_strcmp(type, "Julia") == 0)
		env->type = JULIA;
	else if (ft_strcmp(type, "Glynn") == 0)
		env->type = GLYNN;
	else
	{
		ft_putendl("Please chosse a correct argument\n");
		put_error_usage();
	}
}
