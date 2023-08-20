/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:30:12 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/20 21:42:27 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//@todo add support for complex julia numbers
int32_t	main(int argc, char **argv)
{
	t_program	fractol;

	init_input(argc, argv, &fractol);
	fractol.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!fractol.mlx)
		exit(EXIT_FAILURE);
	fractol.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fractol.mlx, fractol.img, 0, 0);
	mandelbrot(&fractol);
	mlx_loop(fractol.mlx);
	return (EXIT_SUCCESS);
}

	// mlx_close_hook(fractol.mlx, (void *)close_window, NULL);