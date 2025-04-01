/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:30:41 by plerick           #+#    #+#             */
/*   Updated: 2025/04/01 19:55:32 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reinit_img(t_fractol *frac)
{
	
}

void	init_point(t_fractol *frac)
{
	frac->min_x = -2.0;
	frac->max_x = 2.0;
	frac->min_y = -2.0;
	frac->max_y = 2;
}

void	init(t_fractol *frac)
{
	frac->mlx = mlx_init();
	if (!frac->mlx)
		error_exit(frac, 1);
	frac->window = mlx_new_window(frac->mlx, WIDTH, HEIGHT, "fractol");
	if (!frac->window)
		error_exit(frac, 1);
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	if (!frac->img)
		error_exit(frac, 1);
	init_point(frac);
	reinit_img(frac);
}

void	init_frac(t_fractol *frac)
{
	frac->mlx = NULL;
	frac->window = NULL;
	frac->img = NULL;
	frac->buf = NULL;
	frac->fractal = 0;
	frac->cx = 0;
	frac->cy = 0;
	frac->min_x = 0;
	frac->min_y = 0;
	frac->max_x = 0;
	frac->max_y = 0;
}