/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:30:59 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/06 11:48:26 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "structs.h"
# include "color.h"
# include "libft.h"
# include <math.h>
# include "MLX42.h"

/* additional values can be specified in initialize.c */
/* modifying these values can break the program */
# ifndef WIDTH
#  define WIDTH 1024
# endif
# ifndef HEIGHT
#  define HEIGHT 1024
# endif

# define MAX_ITER 30

# define J_REAL_DEFAULT 0.6
# define J_IMAG_DEFAULT -0.6

# define DEFAULT_ZOOM 1

/* defaults for min/max */
# define XY_MIN -2.0
# define XY_MAX 2.0

/* color */
//@todo add color sets blue_gradient, india, tuvalu (maybe intergrad)

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

void		get_user_input(int argc, char **argv, t_program *fractol);
void		initialize_input(int argc, char **argv, t_program *fractol);

/* sets */

/**
 * @brief generates mandelbrot fractal
 */
void		mandelbrot(t_args *fractol);

/**
 * @brief generates julia fractal
 */
void		julia(t_args *args);

/**
 * @brief generates burning_ship fractal
 */
void		burning_ship(t_args *args);

/* utils */

bool		boolcmp(char *argv, char *defined);
char		*str_tolower(char *s);

/* hooks */

void		zoom_on_scroll(double xdelta, double ydelta, void *param);
void		set_keys(void *param);
void		move_keys(t_args *args, void (*set_function));
void		hooks(t_program *fractol);

#endif
