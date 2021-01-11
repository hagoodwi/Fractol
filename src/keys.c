/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:24:07 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/10 19:32:45 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		move(int key, t_all *all)
{
	if (key == 125)
		all->data_image.dy = all->data_image.dy - (0.1 * all->data_image.zoom);
	if (key == 126)
		all->data_image.dy = all->data_image.dy + (0.1 * all->data_image.zoom);
	if (key == 123)
		all->data_image.dx = all->data_image.dx - (0.1 * all->data_image.zoom);
	if (key == 124)
		all->data_image.dx = all->data_image.dx + (0.1 * all->data_image.zoom);
}

void		zoom_iter(int key, t_all *all)
{
	if (key == 24 && all->data_image.zoom > 0.00001)
		all->data_image.zoom *= 0.9;
	if (key == 27 && all->data_image.zoom < 1.7)
		all->data_image.zoom /= 0.9;
	if (key == 69 && all->data_image.max_iter < 250)
		all->data_image.max_iter += 50;
	if (key == 78 && all->data_image.max_iter > 30)
		all->data_image.max_iter -= 50;
	if (key == 82)
		all->data_image.sharpness = all->data_image.sharpness == 2 ? 1 : 2;
	if (key == 49)
		set_def_2(all);
}

void		color_type(int key, t_all *all)
{
	if (key == 87 && all->data_image.type_color != 5)
		all->data_image.type_color = 5;
	if (key == 86 && all->data_image.type_color != 4)
		all->data_image.type_color = 4;
	if (key == 85 && all->data_image.type_color != 3)
		all->data_image.type_color = 3;
	if (key == 84 && all->data_image.type_color != 2)
		all->data_image.type_color = 2;
	if (key == 83 && all->data_image.type_color != 1)
		all->data_image.type_color = 1;
}

void		type_project(int key, t_all *all)
{
	if (key == 18 && all->data_image.type_project != 1)
	{
		all->data_image.type_project = 1;
		set_def_2(all);
	}
	if (key == 19 && all->data_image.type_project != 2)
	{
		all->data_image.type_project = 2;
		set_def_2(all);
	}
	if (key == 20 && all->data_image.type_project != 3)
	{
		all->data_image.type_project = 3;
		set_def_2(all);
	}
	if (key == 21 && all->data_image.type_project != 4)
	{
		all->data_image.type_project = 4;
		set_def_2(all);
	}
	if (key == 23 && all->data_image.type_project != 5)
	{
		all->data_image.type_project = 5;
		set_def_2(all);
	}
}

int			press_key(int key, t_all *all)
{
	move(key, all);
	zoom_iter(key, all);
	color_type(key, all);
	type_project(key, all);
	if (key == 53)
		do_exit(all, 0);
	draw(all);
	return (0);
}
