/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:50:45 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/29 14:53:08 by eplumeco         ###   ########.fr       */
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
# define KEY_1		18
# define KEY_2		19
# define KEY_3		20
# define KEY_MENU	46

/*
** Colors
*/

# define BLUE		0x0000FF
# define CYAN
# define RED		0xFF0000
# define GREEN		0x00FF00
# define WHITE		0xFFFFFF
# define BLACK		0x000000
# define YELLOW		0xFFFF00

/*
** Window
*/

# define IMAGE_X	1500
# define IMAGE_Y	1300
# define STEP		0.1

/*
** Type
*/

# define MANDELBROT 1
# define JULIA 2
# define RANDOM 3


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
	int					i;
	int					j;
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
	char				*addr;
	int					type;
	char				*name;
	int					depth;
}						t_env;

typedef struct			s_move
{
	t_complex			shift;
}						t_move;

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
	t_move				*mov;
}						t_source;

void					put_error_usage(void);
void					put_pixel_to_image(t_env *env, int x, int y, int color);
void					draw_frac(t_env *env);
void					draw_again(t_env *env);
void					mandelbrot(t_env *env);
void					julia(t_env *env);
void					check_fractal(char *type, int ac, t_env *env);
void					random_business(t_env *env);
void					key_shifting(t_env *env, int key_pressed);
void					key_reset(t_env *env);
int						key_commands(int key_pressed, t_env *env);

#endif
