/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:30:12 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/15 15:38:58 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_window(void *param)
{
	t_program	*window;
	
	window = (t_program *)param;
	exit(0);
}

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
	mlx_close_hook(fractol.mlx, (void *)close_window, NULL);
	mandelbrot(&fractol);
	mlx_loop(fractol.mlx);
	return (EXIT_SUCCESS);
}

	// if (!fractol.mlx)
	// {
	// 	perror(mlx_strerror(mlx_errno));
	// 	exit(EXIT_FAILURE);
	// }
	// img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	// if (!img)
	// {
	// 	mlx_close_window(mlx);
	// 	perror(mlx_strerror(mlx_errno));
	// 	exit(EXIT_FAILURE);
	// }
	// if (mlx_image_to_window(mlx, img, 0, 0) == -1)
	// {
	// 	mlx_close_window(mlx);
	// 	perror(mlx_strerror(mlx_errno));
	// 	exit(EXIT_FAILURE);
	// }
	// // mlx_loop_hook(mlx, define_set, mlx);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	// return (0);
