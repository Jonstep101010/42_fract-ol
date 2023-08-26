/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:30:59 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/26 16:57:17 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "structs.h"
# include "libft.h"
# include <math.h>
# include "MLX42.h"

# ifndef WIDTH
#  define WIDTH 1024
# endif
# ifndef HEIGHT
#  define HEIGHT 1024
# endif

# define MAX_ITER 30

/* color */

/**
 * @brief convert rgb to hex using bitwise operators
 * 
 * @param r red
 * @param g green
 * @param b blue
 * @return uint32_t color in hex (0xRRGGBB(FF)))
 */
uint32_t	rgb_to_hex(uint8_t r, uint8_t g, uint8_t b);

// uint32_t	get_iter_color(t_args *args, int x, int y);
uint32_t	rainbow(int iterations, int max_iterations);

/**
 * @brief Get the color object from respective color function
 * 
 * @param args to access color enum
 * @param iter pass
 * @param max_iter pass
 * @return uint32_t 
 */
// uint32_t	get_color(t_args *args, int iter);

/* input/output */

int32_t main(int argc, char **argv);
void	help_page(void);

void	default_vals(t_program *fractol);
void	init_input(int argc, char **argv, t_program *fractol);

/* sets */

void	mandelbrot(t_args *fractol);
// void	julia(t_program *fractol);
// void	define_set(char *set, t_program *fractol);

/* utils */

bool	boolcmp(char *argv, char *defined);
char	*str_tolower(char *s);

// int	main(void);

#endif