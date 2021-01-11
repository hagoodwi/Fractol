/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_func_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:53:45 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/10 19:43:00 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		choose_map(char **av, int ac, t_all *all)
{
	if (ac != 2)
		do_exit(all, 11);
	if (!ft_strcmp(av[1], "julia"))
		return (1);
	if (!ft_strcmp(av[1], "mandelbrot"))
		return (2);
	if (!ft_strcmp(av[1], "celtic"))
		return (3);
	if (!ft_strcmp(av[1], "burning_ship"))
		return (4);
	if (!ft_strcmp(av[1], "mandelbar"))
		return (5);
	else
		do_exit(all, 11);
	return (0);
}

void	print_prompt(void)
{
	ft_putstr("You can choose one parameter from the list:\n");
	ft_putstr("- julia\n");
	ft_putstr("- mandelbrot\n");
	ft_putstr("- celtic\n");
	ft_putstr("- burning_ship\n");
	ft_putstr("- mandelbar\n");
}

void	set_def_2(t_all *all)
{
	all->data_image.dx = 0.0;
	all->data_image.dy = 0.0;
	all->data_image.zoom = 1.0;
	all->data_image.sharpness = 1;
}

int		wheel_button(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (button == 5 && all->data_image.zoom > 0.00001)
		all->data_image.zoom *= 0.9;
	if (button == 4 && all->data_image.zoom < 1.7)
		all->data_image.zoom /= 0.9;
	draw(all);
	return (0);
}

int		do_exit(t_all *all, int code)
{
	if (all->win_mlx != NULL)
		mlx_destroy_window(all->init_mlx, all->win_mlx);
	if (code == 11)
		print_prompt();
	if (code == 1)
		ft_putstr_fd("Error\n", 2);
	exit(0);
	return (0);
}
