/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:32:32 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/05/30 11:50:24 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		type;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	double	julia_re;
	double	julia_im;
	int		color_scheme;
}	t_fractal;

void	init_fractal(t_fractal *fractal, char *name);
void	render_fractal(t_fractal *fractal);
void	put_pixel(t_fractal *fractal, int x, int y, int color);
int		mandelbrot(t_complex c, int max_iter);
int		julia(t_complex z, t_complex c, int max_iter);
int		burning_ship(t_complex c, int max_iter);
int		handle_key(int keycode, t_fractal *fractal);
int		handle_mouse(int button, int x, int y, t_fractal *fractal);
int		close_win(t_fractal *fractal);
int		create_trgb(int t, int r, int g, int b);
int		get_colors(int iteration, t_fractal *fractal);
void	free_fractal(t_fractal *fractal);
int		color_rainbow(int iteration);
int		color_pink_white(double t);
int		color_green_turquoise(double t);
int		color_blue_gradient(double t);
int		color_red_yellow(double t);
int		color_blue_violet(double t);
void	init_graphics(t_fractal *fractal);
void	init_fractal_type(t_fractal *fractal, char *name);
void	init_fractal(t_fractal *fractal, char *name);
void	*ft_memset(void *s, int c, size_t n);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *s);

#endif
