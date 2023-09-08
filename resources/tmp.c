/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:19:57 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/07 19:19:06 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#ifndef	WIDTH
# define WIDTH 1024
#endif
#ifndef HEIGHT
# define HEIGHT 1024
#endif

#define BPP sizeof(int)
static mlx_image_t* image;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	for (int32_t i = 0; i < image->width; ++i)
	{
		for (int32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 512, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

// static uint32_t	getpartial(int iterations, int maxIterations,
// 					uint32_t endcolour)
// {
// 	double		itergrad;
// 	uint8_t		blue;
// 	uint8_t		green;
// 	uint8_t		red;
// 	uint32_t	start_colour;

// 	itergrad = (double)iterations / maxIterations;
// 	start_colour = 0x000000;
// 	blue = (uint8_t)((1 - itergrad) * ((start_colour >> 16) & 0xFF)
// 			+ itergrad * ((endcolour >> 16) & 0xFF));
// 	green = (uint8_t)((1 - itergrad) * ((start_colour >> 8) & 0xFF)
// 			+ itergrad * ((endcolour >> 8) & 0xFF));
// 	red = (uint8_t)((1 - itergrad) * (start_colour & 0xFF)
// 			+ itergrad * (endcolour & 0xFF));
// 	return ((blue << 24) | (green << 16) | (red << 8) | 0xFF);
// }


// uint32_t	intergrad(int iterations, int max_iterations)
// {
// 	if (iterations == max_iterations)
// 		return (0x000000FF);
// 	else if (iterations <= max_iterations / 4)
// 		return ((getpartial(iterations, max_iterations / 4, 0xFF0000)));
// 	else if (iterations <= max_iterations / 2)
// 		return (getpartial(iterations, max_iterations / 2, 0xFFF700));
// 	else if (iterations <= max_iterations * (3 / 4))
// 		return (getpartial(iterations, max_iterations * (3.0 / 4.0), 0x07FF00));
// 	else
// 		return (getpartial(iterations, max_iterations, 0x0012FF));
// }

// static t_rgb	hex_to_rgb(uint32_t color)
// {
// 	t_rgb	rgb;

// 	rgb.r = (color >> 24) & 0xFF;
// 	rgb.g = (color >> 16) & 0xFF;
// 	rgb.b = (color >> 8) & 0xFF;
// 	return (rgb);
// }
