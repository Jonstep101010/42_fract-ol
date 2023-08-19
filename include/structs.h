/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:45:04 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/15 14:32:24 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "fractol.h"
# include <ctype.h>
# include "MLX42.h"


typedef enum e_set
{
	NO_INIT,
	MANDELBROT,
	JULIA,
}	t_set;

typedef enum e_color
{
	default_color,
	rainbow,
}	t_color;

/**
 * @follow-up zoom (in, out), move (x, y)
 * 
 */
typedef	struct s_args 
{
	t_set	set;
	t_color	color;
	int		max_iter;
	double	max_val;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	j_img_num;
	double	j_real_num;
}	t_args;

typedef struct s_program
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_args		pargs;
}	t_program;

#endif