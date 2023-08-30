## How to use:

`./fractol` [[fractal]](#fractal) [[color scheme]](#color-scheme) iter:[iterations](#iterations)

Everything besides the program name is optional and will default safely.
For [julia](#julia-usage) sets, the complex numbers must be passed after the fractal name.

## julia usage:
```bash
# arguments starting with j_ are exclusive to the julia set

./fractol julia rainbow iter:100 j_real_num:0.285 j_imag_num:0.01

# a julia set using the rainbow color scheme and 100 iterations
# with the complex numbers 0.285 (real) + 0.01i (imaginary)
```

`j_real_num` and `j_imag_num` are exclusive to the julia set and	must be passed ***after*** the `fractal` name.

## fractal
- `mandelbrot` based on formula: `z = z^2 + c`
- `julia` based on formula: `z = z^2 + c` with a constant `c`
- `burning_ship` based on formula: `z = |Re(z)| + i|Im(z)| + c`

## color scheme
- `rainbow` rainbow color scheme
- `blue_gradient` based on ultra fractal's blue gradient

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
```

