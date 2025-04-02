/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:04:54 by plerick           #+#    #+#             */
/*   Updated: 2025/04/02 16:55:14 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	msg(char *str, int errno)
{
	ft_putstr_fd(str, 2);
	return(errno);
}

void	error_exit(t_fractol *frac, int code)
{
	if (!frac)
		exit(code);
	if (frac->img)
		mlx_destroy_image(frac->mlx, frac->img);
	if (frac->window && frac->mlx)
		mlx_destroy_window(frac->mlx, frac->window);
	if (frac->mlx)
	{
		mlx_loop_end(frac->mlx);
		mlx_destroy_display(frac->mlx);
		free(frac->mlx);
	}
	exit(code);
}

void	error_msg(t_fractol *frac)
{
	ft_printf("\n What do you want ?\nJulia, type : ./fractol j");
	ft_printf("\nMandelbrot, type : ./fractol m\n\n");
	ft_printf("If you want precise Julia, then type for exemple :\n");
	ft_printf("./fractol j 0.28 0.01\n /!\\ Value must be between 2 / -2");
	error_exit(frac, 1);
}