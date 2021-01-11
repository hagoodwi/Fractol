/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:43:29 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/10 19:14:23 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		cycle4(double c_im, double c_re, t_all *all)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(c_re, c_im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < all->data_image.max_iter)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c_re,
		-2.0 * fabs(z.re * z.im) + c_im);
		iteration++;
	}
	return (iteration);
}

void	burning_ship(t_all *all)
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
			put_pixel(all, x, y, get_colour(cycle4(max.im - y * factor.im,
				min.re + x * factor.re, all), all));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->init_mlx, all->win_mlx, all->id_buffer, 0, 0);
}
