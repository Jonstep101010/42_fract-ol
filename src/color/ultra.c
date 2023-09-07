/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:03:02 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/07 20:54:01 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	ultra_fractal(int iterations, int max_iterations, long double zoom)
{
	double			position;
	t_color_five	rgb;

	(void)zoom;
	position = (double)iterations / max_iterations;
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
	// {0, 7, 0},
	// {((uint8_t) pow(zoom + 10, 2) * 100), 107, 203},
	// {255, 170, 50},
	// {((uint8_t) pow(zoom - 1 * 100, 2)), 255, 255},
	// {0, 2, 0},},
