/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:31:22 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/10 19:15:10 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		cycle3(double c_im, double c_re, t_all *all)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(c_re, c_im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < all->data_image.max_iter)
	{
		z = init_complex(fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + c_re,
		2.0 * z.re * z.im + c_im);
		iteration++;
	}
	return (iteration);
}

void	celtic(t_all *all)
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
			put_pixel(all, x, y, get_colour(cycle3(max.im - y * factor.im,
				min.re + x * factor.re, all), all));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->init_mlx, all->win_mlx, all->id_buffer, 0, 0);
}
