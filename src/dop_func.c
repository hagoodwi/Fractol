/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:41:22 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/10 19:16:50 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_pixel(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->buffer + (y * all->sl + x * (all->bpp / 8));
	*(unsigned int*)dst = color;
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

int			get_colour(int iter, t_all *all)
{
	double		t;
	int			red;
	int			green;
	int			blue;
	int			max_iter2;

	red = 0;
	blue = 0;
	green = 0;
	max_iter2 = all->data_image.max_iter / all->data_image.sharpness;
	iter = iter % max_iter2;
	t = (double)iter / (double)max_iter2;
	if (all->data_image.type_color == 1 || all->data_image.type_color == 4)
		blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	if (all->data_image.type_color == 2 || all->data_image.type_color == 4)
		green = (int)(8.5 * pow((1 - t), 3) * t * 255);
	if (all->data_image.type_color == 3 || all->data_image.type_color == 4)
		red = (int)(8.5 * pow((1 - t), 3) * t * 255);
	if (all->data_image.type_color == 5)
		return (color(iter, max_iter2));
	return ((red << 16) | (green << 8) | blue);
}

int			color(int iter, int max_iter)
{
	double		t;
	int			red;
	int			green;
	int			blue;

	red = 0;
	blue = 0;
	green = 0;
	iter = iter % max_iter;
	t = (double)iter / (double)max_iter;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return ((red << 16) | (green << 8) | blue);
}

void		set_def(t_all *all, int ac, char **av)
{
	all->init_mlx = NULL;
	all->win_mlx = NULL;
	all->id_buffer = NULL;
	all->buffer = NULL;
	all->data_image.dx = 0.0;
	all->data_image.dy = 0.0;
	all->data_image.zoom = 1.0;
	all->data_image.max_iter = 30;
	all->data_image.sharpness = 1;
	all->data_image.type_project = choose_map(av, ac, all);
	all->data_image.type_color = 1;
	all->data_image.k = init_complex(-0.4, 0.6);
}
