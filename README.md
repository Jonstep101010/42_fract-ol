# fract-ol
## Usage:

`./fractol` [[fractal]](#fractal) [[color]](#color-scheme) iter:<[iterations](#iterations)>

Everything besides the program name is optional and will default safely.

## usage julia:
```bash
# arguments starting with j_ are exclusive to the julia set

./fractol julia [color] [iter:<iterations>] [j_real_num:<number.1f>] [j_imag_num:<number.1f>]
./fractol julia rainbow iter:100 j_real_num:0.2 j_imag_num:0.8

# a julia set using the rainbow color scheme and 100 iterations
# with the complex numbers 0.2 (real) + 0.8 (imaginary)
```

`j_real_num` and `j_imag_num` are exclusive to the julia set and	must be passed ***after*** the `fractal` name.

## fractal
- `mandelbrot` based on formula: `z = z^2 + c`
- `julia` based on formula: `z = z^2 + c` with a constant `c`
- `burning_ship` based on formula: `z = |Re(z)| + i|Im(z)| + c`

## color scheme
- `rainbow` rainbow color scheme
- `ultra_fractal` blue gradient
- `shift` with color shifts based on zoom

## iterations
- `iter:[number]` number of iterations to calculate the fractal 
(must be a positive integer)
- lots of iterations can significantly impact performance

## examples:
### mandelbrot or burning_ship:
```bash
./fractol
# defaults to
./fractol mandelbrot rainbow iter:30
# a mandelbrot set using
# the rainbow color scheme 
# and 30 iterations

./fractol burning_ship blue_gradient iter:100
# a burning ship set using
# the blue gradient color scheme
# and 100 iterations
```