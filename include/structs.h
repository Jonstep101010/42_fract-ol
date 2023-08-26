/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:45:04 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/26 22:33:07 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "fractol.h"
# include <ctype.h>
# include "MLX42.h"

/* variables needed in calculate_mandelbrot_color */
typedef struct s_mandelbrot
{
	double	zx;
	double	zy;
	double	new_zx;
	double	new_zy;
	int		iterations;
}	t_mandelbrot;

/* variables needed in calculate_julia_color */
typedef struct s_julia
{
	double	zx;
	double	zy;
	double	new;
	int		iterations;
}	t_julia;

typedef enum e_color
{
	NO_COLOR,
	init_color,
}	t_color;

typedef enum e_set
{
	NO_INIT,
	init_set,
}	t_set;

/**
 * @follow-up zoom (in, out), move (x, y), (close ?)
 * 
 */
typedef struct s_args 
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_set		set;
	t_color		color;
	int			max_iterations;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		j_img_num;
	double		j_real_num;
	uint32_t	(*color_function)(int iter, int max_iter);
}	t_args;

typedef struct s_program
{
	t_args		args;
	void		(*set_function)(t_args *args);
}	t_program;

#endif
