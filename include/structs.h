/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:45:04 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/17 19:18:20 by jschwabe         ###   ########.fr       */
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
}	t_status;

/**
 * @brief Struct for storing the arguments passed to the program.
 *
 */
typedef struct s_args
{
	bool			scroll_zoom;
	double			zoom;
	double			zoom_in;
	double			zoom_out;

	double			xmove;
	double			ymove;
	mlx_t			*mlx;
	mlx_image_t		*img;

	t_status		set;
	t_color			color;
	int				max_iterations;
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			j_imag_num;
	double			j_real_num;
	unsigned int	(*color_function)(double iter, \
		double max_iter, double zoom);
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
