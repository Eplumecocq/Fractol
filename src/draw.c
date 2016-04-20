/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 18:34:34 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/20 18:15:40 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include "mlx.h"

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	((int *)(img->addr))[y * img->mlx_width + x] = color;
}

void	init_line(t_math *m)
{

	m->steep = 0;
	if (ft_absolut(m->x0 - m->x1) < ft_absolut(m->y0 - m->y1))
	{
		ft_swap(&m->x0, &m->y0);
		ft_swap(&m->x1, &m->y1);
		m->steep = 1;
	}
	if (m->x0 > m->x1)
	{
		ft_swap(&m->x0, &m->x1);
		ft_swap(&m->y0, &m->y1);
	}
	m->dx = m->x1 - m->x0;
	m->dy = m->y1 - m->y0;
	m->derror = ft_absolut(m->dy) * 2;
	m->error = 0;
}

void	draw_bres(t_img *img, int dotx, int doty, int color)
{
	t_math	m;

	init_line(&m);
	dotx = m.x0;
	doty = m.y0;
	while (dotx < m.x1)
	{
		if (dotx < img->mlx_width && doty < img->mlx_width && dotx >= 0 && doty >= 0)
		{
			if (m.steep == 1)
				put_pixel_to_image(img, dotx, doty, color);
			else
				put_pixel_to_image(img, doty, dotx, color);
		}
		m.error += m.derror;
		if (m.error > m.dx)
		{
			doty += (m.y1 > m.y0 ? 1 : -1);
			m.derror -= m.dx * 2;
		}
		dotx++;
	}
}

/*t_img		draw(t_mlx *mlx)*/
/*{*/
	/*t_img	img;*/
	/*[>int		dotx = 0;<]*/
	/*[>int		doty = 0;<]*/

	/*[>draw_bres(&img, dotx, doty, 0x00CDCD);<]*/
	/*return (img);*/
/*}*/
