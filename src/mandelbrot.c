/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:59:57 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/20 18:38:10 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

t_complex	*init_mandelbrot(void)
{
	t_complex	*comp = NULL;

	comp = (t_complex*)ft_memalloc(sizeof(t_complex));
	comp->x1 = -2.1;
	comp->x2 = 0.6;
	comp->y1 = -1.2;
	comp->y2 = 1.2;
	comp->ite_max = 50;
	comp->image_x = 270;
	comp->image_y = 240;

	return(comp);
}

void	mandelbrot(t_img *img)
{
	t_complex	*comp;
	int			i = 0;

	comp = init_mandelbrot();
	comp->zoom_x = comp->image_x / (comp->x2 - comp->x1);
	comp->zoom_y = comp->image_y / (comp->y2 - comp->y1);
	comp->a = 0;
	while (comp->a < comp->image_x)
	{
		comp->b = 0;
		while (comp->b < comp->image_y)
		{
			comp->c_r = comp->a / comp->zoom_x + comp->x1;
			comp->c_i = comp->b / comp->zoom_y + comp->y1;
			comp->z_r = 0;
			comp->z_i = 0;
			comp->tmp = comp->z_r;
			comp->z_r = ((comp->z_r * comp->z_r) - (comp->z_i * comp->z_i) + comp->c_r);
			comp->z_i = (2 * comp->z_i * comp->tmp) + comp->c_i;
			i++;
			while ((comp->z_r * comp->z_r) + (comp->z_i * comp->z_i) < 4 && i < comp->ite_max)
			{
				comp->tmp = comp->z_r;
				comp->z_r = ((comp->z_r * comp->z_r) - (comp->z_i * comp->z_i) + comp->c_r);
				comp->z_i = (2 * comp->z_i * comp->tmp) + comp->c_i;
				i++;
			}
			if (i == comp->ite_max)
			{
				ft_putnbr(comp->a);
				ft_putnbr(comp->b);
				put_pixel_to_image(img, comp->a, comp->b, 0xFF8080);
			}
			comp->b++;
		}
		comp->a++;
	}
}



