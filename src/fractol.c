/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:30:12 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/30 21:00:14 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//@todo add support for complex julia numbers
//@todo add zoom capability
//@todo add hooks for keys (zoom, move, toggle zoom on cursor, etc)
//DONE: add exit handling
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
	hooks(&(fractol.args));
	fractol.set_function(&(fractol.args));
	mlx_loop(args->mlx);
	return (EXIT_SUCCESS);
}
