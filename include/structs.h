/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:45:04 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/03 18:13:33 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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

typedef	struct s_args 
{
	t_set	set;
	t_color	color;
}	t_args;

typedef struct s_program
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_args		pargs;
}	t_program;

#endif