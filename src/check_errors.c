/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 12:49:17 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/07 16:04:30 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include <stdlib.h>

void	put_error_usage(void)
{
	/*ft_putchar('\n');*/
	ft_putendl("\x1b[34;01m Usage: ./fractol [Mandelbrot] [Julia] [Random]\n");
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
	else if (ft_strcmp(type, "Random") == 0)
		env->type = RANDOM;
	else if (ft_strcmp(type, "Glynn") == 0)
		env->type = GLYNN;
	else if (ft_strcmp(type, "Burning") == 0)
		env->type = BURNING;
	else
	{
		ft_putendl("Please choose a correct argument\n");
		put_error_usage();
	}
}
