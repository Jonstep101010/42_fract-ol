/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:30:59 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/26 23:20:40 by jschwabe         ###   ########.fr       */
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

uint32_t	rainbow(int iterations, int max_iterations);

/* input/output */

int32_t		main(int argc, char **argv);
void		help_page(void);

void		initialize_input(int argc, char **argv, t_program *fractol);

/* sets */

/**
 * @brief calculate number of operations & pass to color_function
 * @return uint32_t color in hex (return of function)
 */
// static 
// uint32_t	calculate_mandelbrot_color(t_args *args, double cx, double cy);
/**
 * @brief generates mandelbort fractal
 * @follow-up zooming in and out
 */
void		mandelbrot(t_args *fractol);

/**
 * @brief calculate using julia formula
 * @return uint32_t of color_function (pointer)
 */
// static uint32_t	calculate_julia_color(t_args *args, double x, double y);
/**
 * @brief generates julia fractal
 * @follow-up zooming in and out
 * @param args 
 */
void		julia(t_args *args);

void		burning_ship(t_args *args);

/* utils */

bool		boolcmp(char *argv, char *defined);
char		*str_tolower(char *s);

#endif
