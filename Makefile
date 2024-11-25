NAME		  := fractol
.DEFAULT_GOAL := all

# ---------------------------- handle architecture --------------------------- #

ARCH = $(shell uname -m)
ifeq ($(ARCH), arm64)
	GLFW = /opt/homebrew/Cellar/glfw/3.4/lib/
else ifeq ($(ARCH), i386 | x86_64)
	GLFW = /Users/$(USER)/.brew/Cellar/glfw/3.3.8/
endif

# --------------------------------- includes --------------------------------- #

INCS		= ./include \
				./include/libft/ \
				./include/libftprintf/ \
				./include/libgnl/ \
				./include/MLX42/include/MLX42 \
				$(GLFW)/include

LIB			:= ft ftprintf gnl m mlx42
LIBFT		:= include/libft/libft.a
LIBFTPRINTF	:= include/libftprintf/libftprintf.a
LIBGNL		:= include/libgnl/libgnl.a
LIB_MLX		:= include/MLX42/build/libmlx42.a

BUILD_DIR	:= .build

# ---------------------------------------------------------------------------- #
#                                 source files                                 #
# ---------------------------------------------------------------------------- #

VPATH		:= src/ src/sets src/utils src/io src/color

SRC			:= fractol.c
SRC_IO		:= initialize.c help_page.c user_input.c
SRC_SETS	:= mandelbrot.c julia.c burning_ship.c
SRC_COLOR	:= rainbow.c rgb_to_hex.c ultra.c shift.c interpolate.c
SRC_UTILS	:= boolcmp.c str_tolower.c hooks.c move_image.c zoom.c

SRCS		:= $(SRC) $(SRC_IO) $(SRC_SETS) $(SRC_UTILS) $(SRC_COLOR)
# ---------------------------------------------------------------------------- #
#                             compilation arguments                            #
# ---------------------------------------------------------------------------- #

OBJS		:= $(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		?= -g3 -Wall -Wextra -Werror
FRAMEWORKS	:= $(addprefix -framework, $(IOKit) $(Cocoa) $(OpenGL))
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(GLFW) "include/libgnl" "include/libft" "include/libftprintf")
LDLIB		:= $(addprefix -l,"glfw" "gnl" "ft" "ftprintf" "m")

MAKEFLAGS	+= --no-print-directory --silent

DONE		= printf "\033[0;32m\xE2\x9C\x93\033[0m "
DONE_NL		= printf "\033[0;32m\xE2\x9C\x93\n\033[0m"

WIDTH = 1000
HEIGHT = 1000

# ---------------------------------------------------------------------------- #
#                             building the program                             #
# ---------------------------------------------------------------------------- #

update:
	git submodule update --init --recursive
	make -C include/libft; make -C include/libgnl; make -C include/libftprintf
	
all: update $(NAME)

$(LIB_MLX):
	cd include/MLX42 && cmake -B build
	cmake --build $(@D) -j4

$(NAME): $(OBJS) $(LIB_MLX) $(LIBS)
	$(info creating $(NAME) executable)
	$(CC) $(CFLAGS) $(OBJS) -D WIDTH=$(WIDTH) -D HEIGHT=$(HEIGHT) \
	$(LIB_MLX) $(CPPFLAGS) $(LDLIB) $(LDFLAGS) $(FRAMEWORKS) -pthread -o $(NAME)
	$(DONE_NL)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< && $(DONE)
	echo $(notdir $<)

$(BUILD_DIR):
	mkdir -p .build

# ---------------------------------------------------------------------------- #
#                                     rules                                    #
# ---------------------------------------------------------------------------- #

clean:
	$(info Cleaning...)
	make -C include/libft clean; make -C include/libgnl clean; rm -rf $(BUILD_DIR)
	rm -rf include/MLX42/build; $(DONE_NL)

fclean: clean
	make -C include/libft fclean; make -C include/libgnl fclean;
	rm -fv $(LIB_MLX); rm -fv $(NAME);

re:
	$(MAKE) fclean all

.PHONY: run update re clean fclean