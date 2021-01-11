/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:54:25 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/10 19:33:53 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw(t_all *all)
{
	if (all->data_image.type_project == 1)
		julia(all);
	if (all->data_image.type_project == 2)
		mandelbrot(all);
	if (all->data_image.type_project == 3)
		celtic(all);
	if (all->data_image.type_project == 4)
		burning_ship(all);
	if (all->data_image.type_project == 5)
		mandelbar(all);
}

int			main(int ac, char **av)
{
	t_all	all;

	set_def(&all, ac, av);
	if ((all.init_mlx = mlx_init()) == NULL)
		do_exit(&all, 1);
	if ((all.win_mlx = mlx_new_window(all.init_mlx, MAIN_WIN_WIDTH,
			MAIN_WIN_HEIGHT, MAIN_WIN_HEADER)) == NULL)
		do_exit(&all, 1);
	if ((all.id_buffer = mlx_new_image(all.init_mlx,
		MAIN_WIN_WIDTH, MAIN_WIN_HEIGHT)) == NULL)
		do_exit(&all, 1);
	if ((all.buffer = mlx_get_data_addr(
		all.id_buffer, &all.bpp, &all.sl,
		&all.endian)) == NULL)
		do_exit(&all, 1);
	draw(&all);
	mlx_hook(all.win_mlx, 17, 1L << 17, do_exit, &all);
	mlx_hook(all.win_mlx, 2, 1L << 0, press_key, &all);
	mlx_hook(all.win_mlx, 6, 0, julia_motion, &all);
	mlx_hook(all.win_mlx, 4, 0, wheel_button, &all);
	mlx_loop(all.init_mlx);
	do_exit(&all, 0);
}
