/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:30:41 by plerick           #+#    #+#             */
/*   Updated: 2025/04/03 22:41:31 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_img(t_fractol *frac)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*buf;

	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	if (!frac->img)
		error_exit(frac, msg("error image creation", 1));
	buf = mlx_get_data_addr(frac->img, &bits_per_pixel, &size_line, &endian);
	frac->buf = buf;
}

void	reinit_img(t_fractol *frac)
{
	if (frac->mlx && frac->img)
		mlx_destroy_image(frac->mlx, frac->img);
	if (frac->buf)
		frac->buf = NULL;
	init_img(frac);
}

void	init_point(t_fractol *frac)
{
	frac->min_x = -2.0;
	frac->max_x = 2.0;
	frac->min_y = -2.0;
	frac->max_y = frac->min_y + (frac->max_x - frac->min_x) * HEIGHT / WIDTH;
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
	reinit_img(frac); // a quoi ça sert ?
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
