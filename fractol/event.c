/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:46:39 by plerick           #+#    #+#             */
/*   Updated: 2025/04/03 21:55:26 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractol *frac, double zoom)
{
	double	center_x;
	double	center_y;

	center_x = frac->min_x - frac->max_x;
	center_y = frac->max_y - frac->min_y;
	frac->max_x = frac->max_x + (center_x - zoom * center_x) / 2;
	frac->min_x = frac->max_x + zoom * center_x;
	frac->min_y = frac->min_y + (center_y - zoom * center_y) / 2;
	frac->max_y = frac->min_y + zoom * center_y;
}

int	mouse_event(int keycode, int x, int y, t_fractol *frac)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		zoom(frac, 0.5);
	else if (keycode == 5)
		zoom(frac, 2);
	else
		return (0);
	if (frac->fractal == 1)
		get_julia(frac);
	else
		get_mandelbrot(frac);
	return (0);
}

void	move(t_fractol *frac, char direction)
{
	double	center_x;
	double	center_y;

	center_x = frac->max_x - frac->min_x;
	center_y = frac->max_y - frac->min_y;
	if (direction == 'R')
	{
		frac->min_x += center_x * 0.2;
		frac->max_x += center_x * 0.2;
	}
	else if (direction == 'L')
	{
		frac->min_x -= center_x * 0.2;
		frac->max_x -= center_x * 0.2;
	}
	else if (direction == 'D')
	{
		frac->min_y -= center_y * 0.2;
		frac->max_y -= center_y * 0.2;
	}
	else if (direction == 'U')
	{
		frac->min_y += center_y * 0.2;
		frac->max_y += center_y * 0.2;
	}
}
