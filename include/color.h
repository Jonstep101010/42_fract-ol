/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:37:17 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/08 12:55:15 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "structs.h"

/* @follow-up consider set struct unification */
/* ­@follow-up consider implementing iterators as doubles for color functions*/
/* variables needed in calculating colors for sets */
typedef struct s_set
{
	double	zx;
	double	zy;
	double	tmp;
	int		iterations;
	int		max_iterations;
}	t_set;

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
