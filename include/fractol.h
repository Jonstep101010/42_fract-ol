/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:30:59 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/18 11:30:31 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "structs.h"
# include "color.h"
# include "libft.h"
# include <math.h>
# include "MLX42.h"

/* -------------------------------------------------------------------------- */
/*                                  defaults                                  */
/* -------------------------------------------------------------------------- */
/* ----------- additional values can be specified in initialize.c ----------- */

# ifndef WIDTH
#  define WIDTH 1024
# endif
# ifndef HEIGHT
#  define HEIGHT 1024
# endif

# define MAX_ITER 30
# define DEFAULT_ZOOM 1

# define J_REAL_DEFAULT 0.6
# define J_IMAG_DEFAULT -0.6

# define XY_MIN -2.0/*default min*/
# define XY_MAX 2.0/*default max*/

/* -------------------------------------------------------------------------- */
/*                                input/output                                */
/* -------------------------------------------------------------------------- */

int32_t		main(int argc, char **argv);

void		help_page(void);
void		get_user_input(int argc, char **argv, t_program *fractol);
void		initialize_input(int argc, char **argv, t_program *fractol);

/* -------------------------------------------------------------------------- */
/*                                color schemes                               */
/* -------------------------------------------------------------------------- */

/**
 * @brief convert rgb to hex using bitwise operators
 * @return uint32_t color in hex (0xRRGGBB(FF)))
 */
uint32_t	rgb_to_hex(uint8_t r, uint8_t g, uint8_t b);
uint32_t	interpolate_color(t_color_five *rgb, double position);

uint32_t	rainbow(double iterations, double max_iterations, double zoom);
uint32_t	ultra(double iterations, double max_iterations, double zoom);
uint32_t	shift(double iterations, double max_iterations, double zoom);

/* -------------------------------------------------------------------------- */
/*                                fractal sets                                */
/* -------------------------------------------------------------------------- */

/* mandelbrot fractal */
void		mandelbrot(t_args *fractol);

/* julia fractal */
void		julia(t_args *args);

/* burning_ship fractal */
void		burning_ship(t_args *args);

/* -------------------------------------------------------------------------- */
/*                                  utilities                                 */
/* -------------------------------------------------------------------------- */

bool		boolcmp(char *argv, char *defined);
char		*str_tolower(char *s);

/* ---------------------------------- hooks --------------------------------- */

void		zoom_on_scroll(double xdelta, double ydelta, void *param);
void		move_keys(t_args *args, void (*set_function));
void		hooks(t_program *fractol);

#endif
