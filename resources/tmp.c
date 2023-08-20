/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:19:57 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/20 21:00:17 by jschwabe         ###   ########.fr       */
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


// Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
#define BPP sizeof(int32_t)

int32_t	main(void)
{
    // Init mlx with a canvas size of 256x256 and the ability to resize the window.
    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
    
    if (!mlx) exit(EXIT_FAILURE);

    // Create a 128x128 image.
    mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);

    // Set the channels of each pixel in our image to the maximum byte value of 255. 
    // memset(img->pixels, 0xFF0000FF, img->width * img->height * BPP);
	int x = 0;
	int y = 0;
	while (y < HEIGHT)
	{
		mlx_put_pixel(img, x, y, 0xFF0000FF);
		x++;
		if (x == WIDTH)
		{
			y++;
			x = 0;
		}
	}

    // Draw the image at coordinate (0, 0).
    mlx_image_to_window(mlx, img, 0, 0);

    // Run the main loop and terminate on quit.  
    mlx_loop(mlx);
    mlx_terminate(mlx);

    return (EXIT_SUCCESS);
}

// static uint32_t	getpartial(int iterations, int maxIterations,
// 					uint32_t endcolour)//@note shifting using endcolor/bitwise
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


uint32_t interpolateColor(uint32_t start, uint32_t end, double factor) {
	uint8_t r1 = (start >> 24) & 0xFF;
	uint8_t g1 = (start >> 16) & 0xFF;
	uint8_t b1 = (start >> 8) & 0xFF;

	uint8_t r2 = (end >> 24) & 0xFF;
	uint8_t g2 = (end >> 16) & 0xFF;
	uint8_t b2 = (end >> 8) & 0xFF;

	uint8_t r = r1 + (r2 - r1) * factor;
	uint8_t g = g1 + (g2 - g1) * factor;
	uint8_t b = b1 + (b2 - b1) * factor;

	return (r << 24) | (g << 16) | (b << 8) | 0xFF;
}

uint32_t ultra_fractal(int iterations, int max_iterations) {
	double position = (double)iterations / max_iterations;

	uint32_t color1 = 0x000700FF;
	uint32_t color2 = 0x206BCBFF;
	uint32_t color3 = 0xEDFFFF00;
	uint32_t color4 = 0xFFAA00FF;
	uint32_t color5 = 0x000200FF;

	if (position < 0.16) {
		return interpolateColor(color1, color2, position / 0.16);
	} else if (position < 0.42) {
		return interpolateColor(color2, color3, (position - 0.16) / (0.42 - 0.16));
	} else if (position < 0.6425) {
		return interpolateColor(color3, color4, (position - 0.42) / (0.6425 - 0.42));
	} else if (position < 0.8575) {
		return interpolateColor(color4, color5, (position - 0.6425) / (0.8575 - 0.6425));
	} else {
		return color5;
	}
}