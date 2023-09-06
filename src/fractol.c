/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:30:12 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/06 11:51:05 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	main(int argc, char **argv)
{
	t_program	fractol;
	t_args		*args;

	args = &(fractol.args);
	initialize_input(argc, argv, &fractol);
	args->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!args->mlx)
		exit(EXIT_FAILURE);
	args->img = mlx_new_image(args->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(args->mlx, args->img, 0, 0);
	hooks(&fractol);
	fractol.set_function(&(fractol.args));
	mlx_loop(args->mlx);
	return (EXIT_SUCCESS);
}
