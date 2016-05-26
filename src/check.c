/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:07:08 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/26 14:36:29 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	put_error_usage(void)
{
	ft_putchar('\n');
	ft_putendl("\x1b[31;01m Try again with one of the following param :\n");
	ft_putendl("\x1b[31;01m           [Mandelbrot]\n");
	ft_putendl("\x1b[31;01m           [Julia]\n");
	ft_putendl("\x1b[31;01m           [Glynn]\n");
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
		put_error_usage();
}
