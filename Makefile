# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 15:26:30 by gmacias-          #+#    #+#              #
#    Updated: 2024/02/07 17:22:54 by ffornes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT
CC		=	gcc
CFLAGS	=	-O3 -g -Wall -Wextra -Werror -MMD -MP #-fsanitize=address
OS		:= $(shell uname)

###############################################################################
#									SRC										  #
###############################################################################

SRC			=	miniRT.c \
				checkers/checker_dot.c checkers/checker_parse.c \
				error/write_error.c \
				exit/exit.c \
				hooks/key_hooks.c hooks/exit_hooks.c \
				inits/inits.c inits/init_itsc.c \
				camera/camera.c \
				parse/parse_txt.c parse/parse_type.c parse/parse_type_list.c \
				parse/parse_inputs.c parse/parse_inputs2.c \
				ray_tracing/trace_ray_cam.c \
				intersections/rayhit_plane.c intersections/rayhit_sphere.c \
				intersections/rayhit_cylinder.c \
				intersections/rayhit_cylinder_cap.c \
				intersections/get_normal.c \
				utils/array_to.c utils/for_quaternions.c utils/for_vectors.c \
				utils/ft_str_to.c utils/is_space.c \
				utils/my_mlx.c utils/new_vector.c \
				utils/vector_operations.c \
				utils/new_color.c utils/new_material.c utils/colors.c \
				utils/free_data.c utils/quadratic_formula.c

OBJ		=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEPS    =   $(addprefix $(DPS_DIR), $(notdir $(SRC:.c=.d)))

###############################################################################
#									DIR_PATH								  #
###############################################################################

PATH_DIR	=	src_miniRT/
SRC_DIR		=	$(PATH_DIR)src/
OBJ_DIR		=	$(PATH_DIR).obj/
DPS_DIR		=	$(PATH_DIR).dps/

###############################################################################
#									LIBRARIES								  #
###############################################################################

LIB_PATH	=	$(PATH_DIR)Libft
LIB			=	$(LIB_PATH)/libft.a
LIB_FLAGS	=	-L$(LIB_PATH) -lft

ifeq ($(OS), Linux)
	MLX_PATH	= $(PATH_DIR)mlx-linux
	MLX			= $(MLX_PATH)/libmlx.a
	MLX_FLAGS	= -L$(MLX_PATH) -L/usr/lib -lmlx -lXext -lX11 -lm
else
	MLX_PATH	= $(PATH_DIR)mlx
	MLX			= $(MLX_PATH)/libmlx.a
	MLX_FLAGS	= -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
endif

###############################################################################
#									INLUDES									  #
###############################################################################

INCS	= -I $(PATH_DIR)includes/common/ -I $(PATH_DIR)Libft/include/ -I $(MLX_PATH)/

ifeq ($(OS), Linux)
	INCS	+= -I $(PATH_DIR)includes/linux/
else
	INCS	+= -I $(PATH_DIR)includes/macos/
endif

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

all: make_mlx make_lib make_dir $(NAME)
	@echo "" && echo "$(YELLOW)$(NAME) ready to use:$(DEF_COLOR)"

make_dir:
	@mkdir -p $(OBJ_DIR) $(DPS_DIR)
	@echo "$(GREEN)Compiling OBJECTS:$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | make_dir
	@mkdir -p $(dir $@)
	@echo "$(GRAY)Compiling $< to $@ $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	@mv $(basename $@).d $(DPS_DIR)


#						--------	MAKE LIBRARIES	--------							  #

make_mlx:
	@echo "$(GREEN)Checking mlx: $(GRAY)"
	@make -C $(MLX_PATH) 2> /dev/null
	@echo "$(BLUE)Done mlx! $(DEF_COLOR)" && echo ""

make_lib:
	@echo "$(GREEN)Checking Libft: $(GRAY)"
	@$(MAKE) -C $(LIB_PATH)
	@echo "$(BLUE)Done Libft! $(DEF_COLOR)" && echo ""

clean_libs:
	@$(MAKE) clean -s -C $(LIB_PATH)
	@if [ -d "$(MLX_PATH)" ]; then make clean -C $(MLX_PATH) > /dev/null; fi

fclean_libs:
	@$(MAKE) fclean -s -C $(LIB_PATH)
	@if [ -d "$(MLX_PATH)" ]; then rm -rf $(MLX) > /dev/null; fi


#					--------	RULES PROGRAM	--------							  #

$(NAME): Makefile $(LIB) $(MLX) $(OBJ)
	@echo "$(MAGENTA)Compiling $(NAME)$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCS) $(OBJ) -o $(NAME) $(LIB) $(LIB_FLAGS) $(MLX) $(MLX_FLAGS)
	@echo "$(BLUE)Created $(NAME) executable $(DEF_COLOR)"

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
.PHONY: all  clean fclean re make_dir make_mlx make_lib make_dir clean_libs fclean_libs
