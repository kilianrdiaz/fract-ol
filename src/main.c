/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <kroyo-di@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:37:42 by kroyo-di          #+#    #+#             */
/*   Updated: 2025/01/06 20:27:40 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot")
		|| ac == 4 && !ft_strcmp(av[1], "julia"))
	{
		fractal.name = av[1];
		init_fractal(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd("-Incorrect input-\n-->Expected inputs:\n\t", 0);
		ft_putstr_fd("./fractol mandelbrot\n\t./fractol julia <x> <y>\n", 0);
		exit(EXIT_FAILURE);
	}

}
