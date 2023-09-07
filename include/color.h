/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:37:17 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/07 20:52:11 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "structs.h"

/* @follow-up consider set struct unification */
/* ­@follow-up consider implementing iterators as doubles for color functions*/
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

typedef struct s_rgb
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgb;

typedef struct s_color_five
{
	t_rgb	colors[5];
	double	prev_threshold[5];
	double	thresholds[4];
}	t_color_five;

#endif
