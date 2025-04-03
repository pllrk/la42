/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:30:04 by plerick           #+#    #+#             */
/*   Updated: 2025/04/03 21:59:45 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(char *nbr, int i)
{
	double	result;
	double	div;
	int		sign;

	result = 0;
	div = 0.1;
	sign = 1;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	if (nbr[i] == 45 || nbr[i] == 43)
		if (nbr[i++] == 45)
			sign = -1;
	while ((nbr[i] >= 48 && nbr[i] <= 57) && nbr[i] && nbr[i] != '.')
		result = result * 10.0 + nbr[i++] - 48;
	if (nbr[i] == '.')
		i++;
	while ((nbr[i] >= 48 && nbr[i] <= 57) && nbr[i])
	{
		result = result + div * (nbr[i++] - 48);
		div = div * 0.1;
	}
	if (nbr[i] && !ft_isdigit(nbr[i]))
		return (42);
	return (result * sign);
}

void	get_value(t_fractol *frac, char **argv)
{
	if (!ft_strchr(argv[2], '.'))
		error_msg(frac);
	if (!ft_strchr(argv[3], '.'))
		error_msg(frac);
	frac->cx = ft_atod(argv[2], 0);
	frac->cy = ft_atod(argv[3], 0);
	if (frac->cx > 2.0 || frac->cy < -2.0)
		error_msg(frac);
	if (frac->cy > 2.0 || frac->cy < -2.0)
		error_msg(frac);
}

void	do_fractal(t_fractol *frac, int argc, char **argv)
{
	if (!argv[1] || ft_strlen(argv[1]) > 1)
		error_msg(frac);
	if ((argv[1][0] == 'J' || argv[1][0] == 'j') && argc < 5)
	{
		frac->fractal = 1;
		if (argc == 2)
		{
			frac->cx = -0.766667;
			frac->cy = -0.090000;
		}
		else if (argc == 4)
			get_value(frac, argv);
		else
			error_msg(frac);
		get_julia(frac);
	}
	else if ((argv[1][0] == 'M' || argv[1][0] == 'm') && argc < 3)
	{
		frac->fractal = 2;
		frac->cx = -0.766667;
		frac->cx = -0.090000;
		get_mandelbrot(frac);
	}
	else
		error_msg(frac);
}

int	main(int argc, char *argv[])
{
	t_fractol	frac;

	init_frac(&frac);
	if (argc < 2)
		error_msg(&frac);
	init(&frac);
	do_fractal(&frac, argc, argv);
	mlx_hook(frac.window, 17, 0, end_fractol, &frac);
	mlx_key_hook(frac.window, key_event, &frac);
	mlx_mouse_hook(frac.window, mouse_event, &frac);
	mlx_loop(frac.mlx);
}
