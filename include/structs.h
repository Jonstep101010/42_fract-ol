/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:45:04 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/26 11:36:49 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "fractol.h"
# include <ctype.h>
# include "MLX42.h"

typedef enum e_status
{
	NO_INIT,
	NO_COLOR,
	init_set,
	init_color,
}	t_status;

/**
 * @follow-up zoom (in, out), move (x, y)
 * 
 */
typedef	struct s_args 
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_status	set;
	t_status	color;
	int		max_iter;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	j_img_num;
	double	j_real_num;
}	t_args;

typedef struct s_program
{
	t_args		args;
	void		(*set_function)(t_args *args);
	uint32_t	(*color_function)(int iter, int max_iter);
}	t_program;

#endif