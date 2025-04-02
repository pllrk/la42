/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:30:29 by plerick           #+#    #+#             */
/*   Updated: 2025/04/02 18:36:00 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color(t_fractol *frac, int x, int y, int color)
{
	frac->buf[x * 4 + y * WIDTH * 4] = color;
	frac->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8; // que veit dire >> et pourquoi ce calcul
	frac->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	frac->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

int	get_color(int iter)
{
	if (iter == MAX_ITERATIONS)
		return (0x000000);
	return (0x08FF00 + (iter * 255 /MAX_ITERATIONS) * 0x850606);
}