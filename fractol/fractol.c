/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:30:04 by plerick           #+#    #+#             */
/*   Updated: 2025/04/01 19:38:33 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol frac;

	init_frac(&frac);
	if (argc < 2)
		error_msg(&frac);
	init(&frac);
	
}