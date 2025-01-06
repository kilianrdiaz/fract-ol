#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot")
		|| ac == 4 && !ft_strcmp(av[i], "julia"))
	{	
		fractal.name = av[1];
		init_fractal(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_printf("-Incorrect input-\n-->Expected inputs:\n\t./fractol mandelbrot\n\t./fractol julia <x_value> <y_value>\n);
		exit(EXIT_FAILURE);
	}

}
