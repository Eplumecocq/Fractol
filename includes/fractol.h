/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:50:45 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/20 18:38:20 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <math.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	int			width;
	int			height;
}				t_mlx;

typedef struct	t_img
{
	void		*ptr;
	void		*addr;
	int			size_line;
	int			bpp;
	int			endian;
	int			mlx_width;
}				t_img;

typedef struct	s_complex
{
	double		z_r;
	double		z_i;
	double		c_r;
	double		c_i;
	double		tmp;
	int			a;
	int			b;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	int			zoom_x;
	int			zoom_y;
	int			ite_max;
	int			image_x;
	int			image_y;
}				t_complex;

typedef struct	s_math
{
	int			dx;
	int			dy;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			error;
	int			derror;
	int			steep;
}				t_math;

typedef struct	s_color
{
	char		r;
	char		g;
	char		b;
}				t_color;

t_img			draw(t_mlx *mlx);
void			put_pixel_to_image(t_img *img, int x, int y, int color);
void			mandelbrot(t_img *img);
#endif
