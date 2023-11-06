# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 15:26:30 by gmacias-          #+#    #+#              #
#    Updated: 2023/11/06 16:24:21 by ffornes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT
CC		=	gcc
CFLAGS	=	-g -Wall -Wextra -Werror -MMD -MP #-fsanitize=thread

###############################################################################
#									SRC								  #
###############################################################################

SRC		=	miniRT.c \
			mlx_init.c
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

INCS	=	-I ./includes/ -I ./libft/include/ -I ./mlx/

###############################################################################
#									LIBRARIES								  #
###############################################################################

LIB_PATH	= 	./Libft
LIB			=	$(LIB_PATH)/libft.a
LDFLAGS		= 	-L$(LIB_PATH) -lft

MLX_PATH	=	./mlx
MLX			=	mlx/libmlx.a
MLX_FLAGS	=	-Lmlx -lmlx -framework OpenGL -framework Appkit

###############################################################################
#									COLORS								  #
###############################################################################

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
LIGHT_GREEN = \033[1;92m

###############################################################################
#									RULES									  #
###############################################################################

all: make_dir make_mlx make_lib $(NAME)
	@echo "$(NAME) ready to use:"

make_dir:
	@mkdir -p $(OBJ_DIR) $(DPS_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | make_dir
	@echo "Compiling $< to $@"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	@mv $(basename $@).d $(DPS_DIR)
#	@echo "Done!" && echo ""


#						--------	MAKE LIBRARIES	--------							  #

make_mlx:
	@echo "$(GREEN)Checking mlx: $(DEF_COLOR)"
	@make -C mlx
	@echo "$(BLUE)Done mlx! $(DEF_COLOR)"

make_lib:
	@echo "$(GREEN)Checking Libft: $(DEF_COLOR)"
	@$(MAKE) -s -C $(LIB_PATH)
	@echo "$(BLUE)Done Libft! $(DEF_COLOR)"

clean_lib:
	@$(MAKE) clean -s -C $(LIB_PATH) 

fclean_lib:
	@$(MAKE) fclean -s -C $(LIB_PATH)


#					--------	RULES PROGRAM	--------							  #

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)"
	@$(CC) $(CFLAGS) $(INCS) $(OBJ) -o $(NAME) $(LIB)
	@echo "Created $(NAME) executable" && echo ""

clean:	clean_lib
	@echo "Removing ON $(NAME): objects and dependencies..."
	@make clean -C mlx
	@rm -rf $(OBJ_DIR) $(DPS_DIR)
	@echo "Done!" && echo ""

fclean: fclean_lib	clean
	@echo "Removing execute $(NAME)..."
	@rm -f $(NAME)
	@echo "Done!" && echo ""

re: fclean all

###############################################################################
#									OTHERS									  #
###############################################################################

-include $(DEPS)
.PHONY: all make_dir clean fclean re
