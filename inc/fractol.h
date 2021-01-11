/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:55:15 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/10 19:49:05 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAIN_WIN_WIDTH 1000
# define MAIN_WIN_HEIGHT 1000
# define MAIN_WIN_HEADER "FRACTOL"
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_data_image
{
	double			dy;
	double			dx;
	double			zoom;
	int				max_iter;
	int				sharpness;
	int				type_color;
	int				type_project;
	t_complex		k;
}					t_data_image;

typedef struct		s_all
{
	void			*init_mlx;
	void			*win_mlx;
	void			*id_buffer;
	char			*buffer;
	int				bpp;
	int				sl;
	int				endian;
	t_data_image	data_image;
}					t_all;

void				put_pixel(t_all *all, int x, int y, int color);
t_complex			init_complex(double re, double im);
int					get_colour(int iter, t_all *all);
void				set_def(t_all *all, int ac, char **av);
void				set_def_2(t_all *all);
void				mandelbrot(t_all *all);
void				julia(t_all *all);
int					julia_motion(int x, int y, t_all *all);
int					color(int iter, int max_iter);
int					press_key(int key, t_all *all);
int					do_exit(t_all *all, int code);
void				draw(t_all *all);
int					press_key(int key, t_all *all);
int					choose_map(char **av, int ac, t_all *all);
void				def(t_complex *max, t_complex *min,
	t_complex *factor, t_all *all);
void				print_prompt();
void				celtic(t_all *all);
int					wheel_button(int button, int x, int y, t_all *all);
void				burning_ship(t_all *all);
void				mandelbar(t_all *all);
#endif
