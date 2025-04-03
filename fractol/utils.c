/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:30:29 by plerick           #+#    #+#             */
/*   Updated: 2025/04/03 21:47:38 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_event(int keycode, t_fractol *frac)
{
	if (keycode == XK_Escape)
	{
		end_fractol(frac);
		return (0);
	}
	else if (keycode == XK_Up || keycode == XK_w)
		move(frac, 'U');
	else if (keycode == XK_Down || keycode == XK_s)
		move(frac, 'D');
	else if (keycode == XK_Right || keycode == XK_d)
		move(frac, 'R');
	else if (keycode == XK_Left || keycode == XK_a)
		move(frac, 'L');
	else
		return (0);
	if (frac->fractal == 1)
		get_julia(frac);
	else
		get_mandelbrot(frac);
	return (0);
}

int	end_fractol(t_fractol *frac)
{
	error_exit(frac, 0);
	return (0);
}

void	set_color(t_fractol *frac, int x, int y, int color)
{
	frac->buf[x * 4 + y * WIDTH * 4] = color;
	frac->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	frac->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	frac->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

int	get_color(int iter)
{
	if (iter == MAX_ITERATIONS)
		return (0x000000);
	return (0x47ffb9 + (iter * 255 / MAX_ITERATIONS) * 0x5930fc);
}
