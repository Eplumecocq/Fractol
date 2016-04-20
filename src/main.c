/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:49:42 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/20 16:44:51 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "libft.h"

static int	close_win(int keycode, void *param)
{
	param = NULL;

	if (keycode == 53)
		exit (-1);
	else
		return(0);
}

t_mlx	init_mlx(int width, int height, char *title)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, width, height, title);
	mlx.width = width;
	mlx.height = height;
	return(mlx);
}



int		main(void)
{
	t_mlx		mlx;
	t_img		img;
	
	mlx = init_mlx(1000, 1000, "fractol");
	img.ptr = mlx_new_image(mlx.ptr, mlx.width, mlx.height);
	img.mlx_width = mlx.width;
	img.addr = mlx_get_data_addr(img.ptr, &img.size_line, &img.bpp, &img.endian);
	mandelbrot(&img);
	mlx_put_image_to_window(mlx.ptr, mlx.win,img.ptr, 0, 0);
	mlx_key_hook(mlx.win, close_win, 0);
	mlx_loop(mlx.ptr);
	return(0);
}
