/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_fracs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:15:15 by plerick           #+#    #+#             */
/*   Updated: 2025/04/02 18:46:08 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cx, double cy)
{
	int		i;
	double	temp;
	double	x;
	double	y;

	i = 0;
	x = 0.0;
	y = 0.0;
	while (i < MAX_ITERATIONS)
	{
		if ((x * x + y * y) > 4.0)
			break ;
		temp = 2 * x * y + cy;
		x = x * x - y * y + cx;
		y = temp;
		i++;
	}
	return (i);
}

void	get_mandelbrot(t_fractol *frac)
{
	int		iter;
	int		x;
	int		y;
	double	cx;
	double	cy;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cx = frac->min_x + (double)x * (frac->max_x - frac->min_y) / WIDTH;
			cy = frac->max_y + (double)y * (frac->min_y - frac->max_y) / HEIGHT;
			iter = mandelbrot(cx, cy);
			set_color(frac, x, y, get_color(iter));
			x++;
		}
		y++;		
	}
	mlx_put_image_to_window(frac->mlx, frac->window, frac->img, 0, 0);
}

int	julia(t_fractol *frac, double x, double y)
{
	int	i;
	double	temp;

	i = 0;
	temp = 0;
	while (i < MAX_ITERATIONS)
	{
		if ((y * y + x * x) > 4.0)
			break ;
		temp = 2 * x * y + frac->cy; // pourquoi un autre calcul ici, c'est pour la profondeur et l'autre pour le placement ?
		x = x * x - y * y + frac->cx;
		i++;
	}
	return (i);
}

void	get_julia(t_fractol *frac)
{
	int		iter;
	int		x;
	int		y;
	double	cx;
	double	cy;

	x = 0;
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			cx = frac->min_x + (double)x * (frac->max_x - frac->min_y) / WIDTH;
			cy = frac->max_y + (double)y * (frac->min_y - frac->max_y) / HEIGHT;
			iter = julia(frac, cx, cy);
			set_color(frac, x, y, get_color(iter));
			y++;
		}
		x++;		
	}
	mlx_put_image_to_window(frac->mlx, frac->window, frac->img, 0, 0);
}
