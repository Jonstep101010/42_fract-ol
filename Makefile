NAME		:= fractol
.DEFAULT_GOAL := all

INCS		= ./include \
				./include/libft/include \
				./include/MLX42/include/MLX42 \
				$(GLFW)/include

LIB			:= ft m mlx42
LIB_FT		:= include/libft/libft.a
LIB_MLX		:= include/MLX42/build/libmlx42.a
GLFW		= $(HOME)/.brew/Cellar/glfw/3.3.8
MLX42		= $(LIB_MLX) -ldl -L$(GLFW)/lib -lglfw -pthread -lm

BUILD_DIR	:= .build

VPATH		:= src/

SRC			:= fractol.c

SRCS		:= $(SRC) $(SRC_IO) $(SRC_OP) $(SRC_AB) $(SRC_UT)
OBJS		:= $(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
DEPS		:= $(OBJS:.o=.d)

CC			:= clang
CFLAGS		?= -Wunreachable-code -g
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIB_FT), $(dir $(LIB_MLX)), $(GLFW)/lib))
LDLIB		:= $(addprefix -l,$(LIB))

MAKEFLAGS	+= --no-print-directory --silent

DONE		= printf "\033[0;32m\xE2\x9C\x93\033[0m "

all: $(NAME)

$(LIB_FT):
	git submodule init
	git submodule update
	$(MAKE) -C $(@D) -B

$(LIB_MLX):
	git submodule init
	git submodule update
	cd include/MLX42 && cmake -B build
	cd include/MLX42 && cmake --build build -j4

$(NAME): $(OBJS) $(LIB_FT) $(LIB_MLX)
	$(CC) $(CFLAGS) $(OBJS) -D WIDTH=1000 -D HEIGHT=1000 ./include/libft/libft.a ./include/MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)
	$(info creating $(NAME) executable)
	printf "\033[0;32m\xE2\x9C\x93\n\033[0m"

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(DONE)
#info $($<)
	echo $(notdir $<)

$(BUILD_DIR):
	mkdir -p .build

clean:
	$(info Cleaning...)
	make -C $(dir $(LIB_FT)) clean
	rm -rf $(NAME)
	printf "\033[0;32m\xE2\x9C\x93\n\033[0m"

fclean: clean
	rm -fv $(LIB_FT)
	rm -fv $(LIB_MLX)
	rm -rf *.d
	rm -rf $(BUILD_DIR)

update:
	git stash
	git pull
	git submodule update --init
	git stash pop

re:
	$(MAKE) fclean
	$(MAKE) all

run: all
	./$(NAME)

norme:
	-norminette src/ | grep Error

check: norme
	time cd ./resources && sh ./tests.sh && cd ..

upgrade:
	-$(MAKE) update && $(MAKE) re

.PHONY: run update upgrade re vis 
# .SILENT:
-include $(DEPS)