/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:30:12 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/03 21:06:00 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	main(int argc, char **argv)
{
	t_program	fractol;

	init_input(argc, argv, &fractol);
	fractol.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!fractol.mlx)
		exit(EXIT_FAILURE);
	fractol.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fractol.mlx, fractol.img, 0, 0);
	mlx_close_hook(fractol.mlx, (void *)exit, NULL);
	define_set(&fractol);
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
