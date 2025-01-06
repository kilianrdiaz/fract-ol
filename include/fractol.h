#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

# define WIDTH	800
# define HEIGHT	800

typedef struct	s_img
{
	void	*img_ptr; //pointer to image struct;
	char	*pixels_ptr; //points to the actual pixel
	int		bpp; //bits per pixel
	int		endian;
	int		line_len;
}				t_img;

typedef struct	s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
}				t_fractal;

#endif
