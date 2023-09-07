/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:43:27 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/07 20:53:39 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	shift(int iterations, int max_iterations, long double zoom)
{
	double			position;
	t_color_five	rgb;

	position = (double)iterations / max_iterations;
	rgb = (t_color_five)
	{
		.colors = {
	{(uint8_t)(sin(zoom * 2) * 127 + 128),
		(uint8_t)(cos(zoom * 3) * 127 + 128), 0},
	{(uint8_t)(sin(zoom * 4) * 50 + 32),
		(uint8_t)(cos(zoom * 5) * 53 + 54), 203},
	{237, 255, 255},
	{255, 170, (uint8_t)(sin(zoom * 6) * 127 + 128)},
	{0, 2, 0}},
		.prev_threshold = {0, 0.16, 0.42, 0.6425},
		.thresholds = {0.16, 0.42, 0.6425, 0.8575},
	};
	return (interpolate_color(&rgb, position));
}
