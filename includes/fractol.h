/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:50:45 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/24 18:48:44 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"

/*
** Key commands
*/

# define KEY_ESC		53
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_ITEP		69
# define KEY_ITEM		78
# define KEY_RESET		15
# define KEY_C			8
# define WHEEL_ZOOM_U	5 	
# define WHEEL_ZOOM_D	4
# define KEY_O			31
# define MLX_MOD_SHIFT	1 << 0
# define KEY_FRAC_1		18
# define KEY_FRAC_2		19
# define KEY_FRAC_3		20

/*
** Colors
*/

# define BLUE		0x0000FF
# define CYAN		0x00FFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define WHITE		0xFFFFFF
# define BLACK		0x000000
# define YELLOW		0xFFFF00

/*
** Window
*/

# define IMAGE_X	800
# define IMAGE_Y	600
# define IMAGE_DX	(double)IMAGE_X
# define IMAGE_DY	(double)IMAGE_Y

/*
** Type
*/

# define MANDELBROT 1
# define JULIA		2
# define GLYNN		3

typedef	struct			s_img
{
	char				*addr;
	void				*img_ptr;
	int					bpp;
	int					size_line;
	int					endian;
}						t_img;

typedef struct			s_env
{
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				zoom_x;
	double				zoom_y;
	int					init;
	int					x;
	int					y;
	int					z;
	int					itemax;
	int					type;
	int					r;
	int					g;
	int					b;
	char				*name;
	int					on;
	double				tmp;
	void				*mlx_ptr;
	void				*win_ptr;
	t_img				img;	
}						t_env;

void					put_error_usage(void);
void					check_fractal(char *type, int ac, t_env *env);
void					put_pixel(t_env *env, int r, int g, int b);
void					put_pixel_to_image(t_env *env, int x, int y, int color);
int						draw_fractal(t_env *env);
t_env					init_fractal(t_env *env);
t_env					mandelbrot(t_env *env);
void					draw_mandelbrot(t_env *env);
void					draw_julia(t_env *env);
t_env					julia(t_env *env);
void					draw_glynn(t_env *env);
t_env					glynn(t_env *env);
void					key_reset(int key_pressed, t_env *env);
int						key_commands(int key_pressed, t_env *env);
int						motion_commands(int x, int y, t_env *env);
void					shifting_y(int key_pressed, t_env *env);
void					shifting_x(int key_pressed, t_env *env);
void					switch_fractal(int key_pressed, t_env *env);
void					zoom(int key_pressed, int x, int y, t_env *env);
int						mouse_commands(int key_pressed, int x, int y, t_env *env);

#endif
