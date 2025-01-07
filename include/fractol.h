/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <kroyo-di@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:38:27 by kroyo-di          #+#    #+#             */
/*   Updated: 2025/01/07 19:59:32 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# define WIDTH	800
# define HEIGHT	800

# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF
# define ORANGE		0xFFA500
# define PINK		0xFF69B4
# define PURPLE		0x800080
# define LIME		0x00FF40
# define TURQUOISE	0x40E0D0
# define INDIGO		0x4B0082
# define WHITE 		0xFFFFFF
# define BLACK 		0x000000

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

//	Pixels buffer values from mlx_get_data_addr()
typedef struct s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr; //points to the actual pixel
	int		bpp; //bits per pixel
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractal
{
	char	*name;
	//MLX
	void	*mlx_connection;
	void	*mlx_window;
	//Image
	t_img	img;
	//Hook values
	double	escape_value;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		iterations_def;
}				t_fractal;

size_t		ft_strlen(const char *str);
int			ft_strcmp(char *s1, char *s2);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
void		ft_putstr_fd(char *s, int fd);
void		init_fractal(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
double		atodbl(char *s);
double		map(double num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif
