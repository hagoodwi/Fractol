/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:48:39 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/10 19:38:48 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_motion(int x, int y, t_all *all)
{
	if (x >= 0 && x < MAIN_WIN_WIDTH && y >= 0 && y < MAIN_WIN_HEIGHT
		&& all->data_image.type_project == 1)
	{
		all->data_image.k = init_complex(4 * ((double)x / MAIN_WIN_WIDTH - 0.5),
			4 * ((double)(MAIN_WIN_HEIGHT - y) / MAIN_WIN_HEIGHT - 0.5));
		julia(all);
	}
	return (0);
}

void	def(t_complex *max, t_complex *min, t_complex *factor, t_all *all)
{
	*min = init_complex((-2.0 * all->data_image.zoom) + all->data_image.dx,
		(-2.0 * all->data_image.zoom) + all->data_image.dy);
	*max = init_complex((2.0 * all->data_image.zoom) + all->data_image.dx,
		(2.0 * all->data_image.zoom) + all->data_image.dy);
	*factor = init_complex((max->re - min->re) / (MAIN_WIN_WIDTH - 1),
		(max->im - min->im) / (MAIN_WIN_HEIGHT - 1));
}

int		cycle(double c_im, double c_re, t_all *all)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(c_re, c_im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < all->data_image.max_iter)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + all->data_image.k.re,
		2.0 * z.re * z.im + all->data_image.k.im);
		iteration++;
	}
	return (iteration);
}

void	julia(t_all *all)
{
	t_complex	max;
	t_complex	min;
	t_complex	factor;
	int			x;
	int			y;

	def(&max, &min, &factor, all);
	y = 0;
	while (y < MAIN_WIN_HEIGHT)
	{
		x = 0;
		while (x < MAIN_WIN_WIDTH)
		{
			put_pixel(all, x, y, get_colour(cycle(max.im - y * factor.im,
				min.re + x * factor.re, all), all));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->init_mlx, all->win_mlx, all->id_buffer, 0, 0);
}
