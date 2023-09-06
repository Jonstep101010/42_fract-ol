/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:45:04 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/06 11:52:37 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "fractol.h"
# include <ctype.h>
# include "MLX42.h"

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
 * @brief Struct for storing the arguments passed to the program.
 * 
 */
typedef struct s_args 
{
	long double	zoom;

	long double	zoom_in;
	long double	zoom_out;

	bool		scroll_zoom;

	long double	xmove;
	long double	ymove;

	mlx_t		*mlx;
	mlx_image_t	*img;
	t_set		set;
	t_color		color;
	int			max_iterations;
	long double	xmin;
	long double	xmax;
	long double	ymin;
	long double	ymax;
	double		j_imag_num;
	double		j_real_num;
	uint32_t	(*color_function)(int iter, int max_iter);
}	t_args;

/**
 * @brief Struct for storing the program functions & arguments.
 */
typedef struct s_program
{
	t_args		args;
	void		(*set_function)(t_args *args);
	void		(*move_keys)(t_args *args, void (*set_function));
}	t_program;

#endif
