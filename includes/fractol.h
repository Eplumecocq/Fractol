/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:50:45 by eplumeco          #+#    #+#             */
/*   Updated: 2016/05/07 16:19:25 by eplumeco         ###   ########.fr       */
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

# define KEY_ESC	53
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_RESET	15
# define KEY_ZOOM_U 61 	
# define KEY_ZOOM_D	45
# define KEY_DEPTH_U 65451
# define KEY_DEPTH_D 65453
# define KEY_O		31
# define KEY_RESET_ALL 0
# define MLX_MOD_SHIFT	1 << 0

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
# define STEP		0.1

/*
** Type
*/

# define MANDELBROT 1
# define JULIA		2
# define RANDOM		3
# define GLYNN		4
# define BURNING	5


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
	double				coeff1;
	double				coeff2;
	int					i;
	int					j;
	double				k;
	double				jc_r;
	double				jc_i;
	double				gc_r;
	double				gc_i;
	double				zoom_x;
	double				zoom_y;
	double				zoom;
	double				image_x;
	double				image_y;
	double				imax;
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
	t_complex			*comp;
	int					on;
	char				*addr;
	int					type;
	char				*name;
	int					depth;
}						t_env;


typedef struct			s_zoom
{
	double				x_cent;
	double				y_cent;
	double				diff_x;
	double				diff_y;
}						t_zoom;

typedef struct			s_source
{
	t_complex			*comp;
	t_env				*env;
}						t_source;

void					put_error_usage(void);
void					put_pixel_to_image(t_env *env, int x, int y, int color);
void					draw_frac(t_env *env);
void					draw_again(t_env *env);
void					mandelbrot(t_env *env);
void					julia2(t_env *env);
void					check_fractal(char *type, int ac, t_env *env);
void					random_business(t_env *env);
void					key_shifting(t_env *env, int key_pressed);
void					key_reset(t_env *env);
void					reset_all(t_env *env);
int						key_commands(int key_pressed, t_env *env);
void					apply_zoom(t_env *env, int key_pressed, int x, int y);
void					go_deep(t_env *env, int key_pressed);
int						mouse_commands(int key_pressed, int x, int y, t_env *env);
int						motion_commands(int x, int y, t_env *env);
void					color_mandelbrot(t_env *env, t_complex *comp);
void					color_julia(t_env *env, t_complex *comp);
void					color_business(t_env *env, t_complex *comp);
void					glynn(t_env *env);
void					burning_ship(t_env *env);
t_complex				init_tmp(t_complex *comp);

#endif
