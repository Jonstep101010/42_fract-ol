/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:03:02 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/06 21:05:55 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_color_rgb
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_color_rgb;

typedef struct s_color_five
{
	t_color_rgb	color1;
	t_color_rgb	color2;
	t_color_rgb	color3;
	t_color_rgb	color4;
	t_color_rgb	color5;
}	t_color_five;

static t_color_rgb	hex_to_rgb(uint32_t color)
{
	t_color_rgb	rgb;

	rgb.r = (color >> 24) & 0xFF;
	rgb.g = (color >> 16) & 0xFF;
	rgb.b = (color >> 8) & 0xFF;
	return (rgb);
}

uint32_t	interpolate_color(t_color_rgb start, t_color_rgb end, double factor)
{
	start.r += (end.r - start.r) * factor;
	start.g += (end.g - start.g) * factor;
	start.b += (end.b - start.b) * factor;
	return (rgb_to_hex(start.r, start.g, start.b));
}

uint32_t	ultra_fractal(int iterations, int max_iterations)
{
	double			position;
	t_color_five	rgb;

	position = (double)iterations / max_iterations;
	rgb = (t_color_five)
	{
		.color1 = {0, 7, 0},
		.color2 = {32, 107, 203},
		.color3 = {237, 255, 255},
		.color4 = {255, 170, 0},
		.color5 = {0, 2, 0},
	};
	if (position < 0.16)
		return (interpolate_color(rgb.color1, rgb.color2, position / 0.16));
	else if (position < 0.42)
		return (interpolate_color(rgb.color2, rgb.color3,
				(position - 0.16) / (0.42 - 0.16)));
	else if (position < 0.6425)
		return (interpolate_color(rgb.color3, rgb.color4,
				(position - 0.42) / (0.6425 - 0.42)));
	else if (position < 0.8575)
		return (interpolate_color(rgb.color4, rgb.color5,
				(position - 0.6425) / (0.8575 - 0.6425)));
	else
		return (rgb_to_hex(rgb.color5.r, rgb.color5.g, rgb.color5.b));
}
