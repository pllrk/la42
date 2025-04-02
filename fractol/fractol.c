/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:30:04 by plerick           #+#    #+#             */
/*   Updated: 2025/04/02 18:46:43 by plerick          ###   ########.fr       */
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
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32) // ???? pourquoi ces valeurs
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
		div = div * 0.1; // pourquoi cette ligne
	}
	if (nbr[i] && !ft_isdigit(nbr[i]))
		return (42); // pk 42 ?
	return (result * sign);	
}

void	get_value(t_fractol *frac, char **argv)
{
	if (!ft_strchr(argv[2], '.')) // Look for what is a double value
		error_msg(frac);
	if (!ft_strchr(argv[3], '.')) // Look for what is a double value
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
		error_msg(&frac);
	if ((argv[1][0] == 'J' || argv[1][0] == 'j') && argc < 5)
	{
		frac->fractal = 1; //what for ??
		if (argc == 2)
		{
			frac->cx = -0.507076;
			frac->cy = 1.566608;
		}
		else if (argc == 4)
			get_value(frac, argv);
		else
			error_msg(frac);
		frac_julia(frac);
	}
	else if ((argv[1][0] == 'M' || argv[1][0] == 'm') && argc < 3)
	{
		frac->fractal = 2; // same, pourquoi 2 ?
		frac->cx = -0.485792;
		frac->cx = 0.900792;
		get_mandelbrot(frac);
	}
	else
		error_msg(frac);	
}

int	main(int argc, char **argv)
{
	t_fractol frac;

	init_frac(&frac);
	if (argc < 2)
		error_msg(&frac);
	init(&frac);
	
}