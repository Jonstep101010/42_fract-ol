/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:03:02 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/08 15:07:29 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	ultra(double iterations, double max_iterations, double zoom)
{
	double			position;
	t_color_five	rgb;

	(void)zoom;
	position = iterations / max_iterations;
	rgb = (t_color_five)
	{
		.colors = {
	{0, 7, 0},
	{32, 107, 203},
	{237, 255, 255},
	{255, 170, 0},
	{0, 2, 0},},
		.prev_threshold = {0, 0.16, 0.42, 0.6425},
		.thresholds = {0.16, 0.42, 0.6425, 0.8575},
	};
	return (interpolate_color(&rgb, position));
}
