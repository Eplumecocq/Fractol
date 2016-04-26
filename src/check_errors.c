/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 12:49:17 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/26 18:55:32 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include <stdlib.h>

void	put_error_usage(void)
{
	ft_putendl("Usage : ./fractol [Mandelbrot] [Julia]");
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
		put_error_usage();
		ft_putendl("Please choose the correct argument");
	}
}
