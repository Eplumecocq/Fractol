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

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"

// key commands

# define KEY_ESC 53
# define KEY_UP 
# define KEY_DOWN
# define KEY_LEFT
# define KEY_RIGHT

// colors

# define BLUE 0x0000FF
# define CYAN
# define RED 0xFF0000
# define GREEN 0x00FF00
# define WHITE 0xFFFFFF
# define BLACK 0x000000

// settings

# define IMAGE_X 800
# define IMAGE_Y 600

// fractal type

# define MANDELBROT 1
# define JULIA 2

typedef struct			s_complex
{
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				tmp1;
	double				tmp2;
	int					x;
	int					y;
	int					z;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
}						t_complex;

typedef struct			s_env
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					bpp;	
	int					size_line;
	int					endian;
	int					init;
	int					zoom;
	struct s_complex	*comp;
	char				*addr;
	int					type;
	char				*name;
	int					depth;
}						t_env;

void					put_error_usage(void);
void					put_pixel_to_image(t_env *env, int x, int y, int color);
void					draw_frac(t_env *env);
void					mandelbrot(t_env *env);
void					check_fractal(char *type, int ac, t_env *env);

#endif
