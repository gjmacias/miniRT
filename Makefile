# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 15:26:30 by gmacias-          #+#    #+#              #
#    Updated: 2023/11/22 17:11:13 by ffornes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT
CC		=	gcc
CFLAGS	=	-g -Wall -Wextra -Werror -MMD -MP #-fsanitize=thread
OS		:= $(shell uname)

###############################################################################
#									SRC								  #
###############################################################################

SRC			=	miniRT.c \
				checkers/checker_dot.c checkers/checker_parse.c \
				error/write_error.c \
				exit/exit.c \
				hooks/key_hooks.c hooks/exit_hooks.c \
				inits/init_mlx.c inits/init_parameters.c \
				inputs/camera/camera.c \
				parse/parse_txt.c parse/parse_type.c parse/parse_type_list.c \
				parse/parse_inputs.c parse/parse_inputs2.c \
				utils/array_to.c utils/for_matrix.c utils/for_vectors.c \
				utils/ft_str_to.c utils/intersections.c utils/is_space.c\
				utils/my_mlx.c utils/new_vector.c \
				utils/vector_operations.c \
				tests/print.c tests/print_matrix.c tests/print_vector.c

OBJ		=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEPS	=	$(addprefix $(DPS_DIR), $(SRC:.c=.d))

###############################################################################
#									DIR_PATH								  #
###############################################################################

SRC_DIR	=	src/
OBJ_DIR	=	obj/
DPS_DIR	=	dps/

###############################################################################
#									LIBRARIES								  #
###############################################################################

LIB_PATH	=	./Libft
LIB			=	$(LIB_PATH)/libft.a
LIB_FLAGS	=	-L$(LIB_PATH) -lft

ifeq ($(OS), Linux)
	MLX_PATH	= ./mlx-linux
	MLX			= $(MLX_PATH)/libmlx.a
	MLX_FLAGS	= -L$(MLX_PATH) -L/usr/lib -lmlx -lXext -lX11 -lz -lm
else
	MLX_PATH	= ./mlx
	MLX			= $(MLX_PATH)/libmlx.a
	MLX_FLAGS	= -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
endif

###############################################################################
#									INLUDES									  #
###############################################################################

INCS	=	-I ./includes/ -I ./Libft/include/ -I $(MLX_PATH)/

###############################################################################
#									COLORS									  #
###############################################################################

DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
LIGHT_GREEN	= \033[1;92m

###############################################################################
#									RULES									  #
###############################################################################

all: make_dir make_mlx make_lib $(NAME)
	@echo "$(CYAN)$(NAME) ready to use:$(DEF_COLOR)"

make_dir:
	@mkdir -p $(OBJ_DIR) $(DPS_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | make_dir
	@mkdir -p $(dir $@)
	@echo "$(GRAY)Compiling $< to $@ $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	@mv $(basename $@).d $(DPS_DIR)


#						--------	MAKE LIBRARIES	--------							  #

make_mlx:
	@echo "$(GREEN)Checking mlx: $(DEF_COLOR)"
	@make -C $(MLX_PATH) 2> /dev/null
	@echo "$(BLUE)Done mlx! $(DEF_COLOR)"

make_lib:
	@echo "$(GREEN)Checking Libft: $(DEF_COLOR)"
	@$(MAKE) -s -C $(LIB_PATH)
	@echo "$(BLUE)Done Libft! $(DEF_COLOR)"

clean_libs:
	@$(MAKE) clean -s -C $(LIB_PATH)
	@if [ -d "$(MLX_PATH)" ]; then make clean -C $(MLX_PATH) > /dev/null; fi

fclean_libs:
	@$(MAKE) fclean -s -C $(LIB_PATH)
	@if [ -d "$(MLX_PATH)" ]; then rm -rf $(MLX) > /dev/null; fi


#					--------	RULES PROGRAM	--------							  #

$(NAME): $(LIB) $(MLX) $(OBJ)
	@echo "$(GREEN)Compiling $(NAME)$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCS) $(OBJ) -o $(NAME) $(LIB) $(LIB_FLAGS) $(MLX) $(MLX_FLAGS)
	@echo "$(BLUE)Created $(NAME) executable $(DEF_COLOR)" && echo ""

clean:	clean_libs
	@echo "$(RED)Removing ON $(NAME), $(LIB_PATH) and $(MLX_PATH): objects and dependencies... $(DEF_COLOR)"
	@rm -rf $(OBJ_DIR) $(DPS_DIR)
	@echo "$(BLUE)Done!$(DEF_COLOR)" && echo ""

fclean: fclean_libs	clean
	@echo "$(RED)Removing execute $(NAME)... $(DEF_COLOR)"
	@rm -f $(NAME)
	@echo "$(BLUE)Done!$(DEF_COLOR)" && echo ""

re: fclean all

###############################################################################
#									OTHERS									  #
###############################################################################

-include $(DEPS)
.PHONY: all make_dir clean fclean re
