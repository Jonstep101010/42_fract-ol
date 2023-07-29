/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:30:12 by jschwabe          #+#    #+#             */
/*   Updated: 2023/07/28 17:17:34 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#ifndef	WIDTH
# define WIDTH 1024
#endif
#ifndef HEIGHT
# define HEIGHT 1024
#endif

/*call for Mandelbrot/Julia set*/
void	host_set_call(mlx_image_t *img ,mlx_t *mlx, char **argv)
{
	int	x = 0;
	int	y = 0;
	// while (y < HEIGHT)
	// {
	// 	mlx_put_pixel(img, x, y, 0xFF0000FF);
	// 	x= WIDTH;
	// 	if (x == WIDTH)
	// 	{
	// 		y++;
	// 		x -=y;
	// 	}
	// }
	while (y < HEIGHT)
	{
		mlx_put_pixel(img, x, y, 0xFFFFFF);
		x++;
		if (x == WIDTH || x > WIDTH - y)
		{
			y++;
			x = 0;
		}
	}
	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		mlx_put_pixel(img, x, y, 0xFF0000FF);
		if (x == 0)
			x= WIDTH;
		else
			x++;
		if (x == WIDTH)
		{
			y++;
			x -=y;
		}
	}
	
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	
	mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!mlx)
	{
		perror(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
	{
		mlx_close_window(mlx);
		perror(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, img, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		perror(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	host_set_call(img, mlx, argv);
	// mlx_loop_hook(mlx, host_set_call, mlx);
	
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
