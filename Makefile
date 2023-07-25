NAME		:= fractol
.DEFAULT_GOAL := all

INCS		:= ./include \
				./include/libft
				./include/MLX42

LIB			:= ft m
LIB_FT		:= include/libft/libft.a
INCS		:= include \
	include/libft/include

BUILD_DIR	:= .build

VPATH		:= src/ src/io src/operations src/sorting src/utils

SRC			:= fractol.c

SRCS		:= $(SRC) $(SRC_IO) $(SRC_OP) $(SRC_AB) $(SRC_UT)
OBJS		:= $(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
DEPS		:= $(OBJS:.o=.d)

CC			:= clang
CFLAGS		?= -Wall -Wextra -Werror
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIB_FT)))
LDLIB		:= $(addprefix -l,$(LIB))

MAKEFLAGS	+= --silent --no-print-directory

DONE		= printf "\033[0;32m\xE2\x9C\x93\033[0m "

all: $(NAME)

$(NAME): $(OBJS) $(LIB_FT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIB) -o $(NAME)
	$(info creating $(NAME) executable)
	printf "\033[0;32m\xE2\x9C\x93\n\033[0m"

$(LIB_FT):
	$(MAKE) -C $(@D) -B

# $(GIT_LIBFT)
# 	git clone https://github.com/Jonstep101010/libft.git ./include

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
	make -C $(dir $(LIB_FT)) fclean
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

vis:
	$(MAKE) all
	./push_swap_visualizer/build/bin/visualizer

run: re
	-./$(NAME)

norme:
	-norminette src/ | grep Error

check: norme
	time cd ./resources && sh ./tests.sh && cd ..

upgrade:
	-$(MAKE) update && $(MAKE) re

.PHONY: run update upgrade re vis
# .SILENT:
-include $(DEPS)