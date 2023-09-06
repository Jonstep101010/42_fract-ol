/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:37:17 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/06 10:19:18 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "structs.h"

/* variables needed in calculating mandelbrot color */
typedef struct s_mandelbrot
{
	double	zx;
	double	zy;
	double	tmp_zx;
	int		iterations;
	int		max_iterations;
}	t_mandelbrot;

/* variables needed in calculating julia color */
typedef struct s_julia
{
	double	zx;
	double	zy;
	double	tmp;
	int		iterations;
	int		max_iterations;
}	t_julia;

/* variables needed in calculating burning_ship color */
typedef struct s_burning_ship
{
	double	zx;
	double	zy;
	double	tmp;
	int		iterations;
	int		max_iterations;
}	t_burning_ship;

#endif
