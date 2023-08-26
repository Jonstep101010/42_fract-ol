NAME		:= fractol
.DEFAULT_GOAL := all


MLX42		= $(LIB_MLX) -ldl -L$(GLFW)/lib -lglfw -pthread -lm
#	$(CC) -o $(NAME) $(SOURCE) $(LIBFT) -D WIDTH=$(WIDTH) -D HEIGHT=$(HEIGHT) ./mlx/build/libmlx42.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/" -framework Cocoa -framework OpenGL -framework IOKit
ARCH = $(shell uname -m)
ifeq ($(ARCH), arm64)
	GLFW = /opt/homebrew/Cellar/glfw/3.3.8/
else ifeq ($(ARCH), i386 | x86_64)
	GLFW = /Users/$(USER)/.brew/Cellar/glfw/3.3.8/
endif

INCS		= ./include \
				./include/libft/include \
				./include/MLX42/include/MLX42 \
				$(GLFW)/include

LIB			:= ft m mlx42
LIB_FT		:= include/libft/libft.a
LIB_MLX		:= include/MLX42/build/libmlx42.a

BUILD_DIR	:= .build

VPATH		:= src/ src/sets src/utils src/io src/color

SRC			:= fractol.c
SRC_IO		:= initialize.c help_page.c 
SRC_SETS	:= mandelbrot.c julia.c
SRC_COLOR	:= rainbow.c rgb_to_hex.c
SRC_UTILS	:= boolcmp.c str_tolower.c

SRCS		:= $(SRC) $(SRC_IO) $(SRC_SETS) $(SRC_UTILS) $(SRC_COLOR)
OBJS		:= $(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
DEPS		:= $(OBJS:.o=.d)

CC			:= clang
CFLAGS		?= -g3 -Wall -Wextra -Werror -Wpedantic
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIB_FT), $(dir $(LIB_MLX)), $(GLFW)/lib))
LDLIB		:= $(addprefix -l,$(LIB))

MAKEFLAGS	+= --no-print-directory --silent

DONE		= printf "\033[0;32m\xE2\x9C\x93\033[0m "

WIDTH = 1000
HEIGHT = 1000

all: $(NAME)

$(LIB_FT):
	$(MAKE) -C $(@D) -B

$(LIB_MLX):
	cd include/MLX42 && cmake -B build
	cmake --build $(@D) -j4

$(NAME): $(OBJS) $(LIB_FT) $(LIB_MLX)
	$(info creating $(NAME) executable)
	$(CC) $(CFLAGS) $(OBJS) -D WIDTH=$(WIDTH) -D HEIGHT=$(HEIGHT) -D DEBUG=1 ./include/libft/libft.a ./include/MLX42/build/libmlx42.a -Iinclude -MMD -MP -lglfw -L"$(GLFW)/lib/" -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)
	printf "\033[0;32m\xE2\x9C\x93\n\033[0m"
# $(CC) $(CFLAGS) $(OBJS) -D WIDTH=1000 -D HEIGHT=1000 -D DEBUG=1 ./include/libft/libft.a ./include/MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< && $(DONE)
	echo $(notdir $<)
#info $($<)
$(BUILD_DIR):
	mkdir -p .build

clean:
	$(info Cleaning...)
	make -C $(dir $(LIB_FT)) clean
	rm -rf .build
	printf "\033[0;32m\xE2\x9C\x93\n\033[0m"

fclean: clean
	rm -fv $(LIB_FT)
	rm -fv $(LIB_MLX)
	rm -f $(NAME)

update: fclean
	git submodule update --init
# git stash
# git pull
# git stash pop

re:
	$(MAKE) fclean
	$(MAKE) all

run: all
	./$(NAME)

norme:
	clear
	-norminette src/ | grep Error

upgrade:
	-$(MAKE) update && $(MAKE) re

.PHONY: run update upgrade re
# .SILENT:
-include $(DEPS)