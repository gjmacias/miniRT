# Target and dependency definitions
NAME	=	miniRT
CC		=	gcc
CFLAGS	=	-g -Wall -Wextra -Werror -MMD -MP #-fsanitize=thread

# Source and object file lists
SRC		=	
OBJ		=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEPS	=	$(addprefix $(DPS_DIR), $(SRC:.c=.d))

# Directory paths
SRC_DIR	=	src/
OBJ_DIR	=	obj/
DPS_DIR	=	dps/

# Include directory
INCS	=	-I./includes/

# Include Library
LIB	=	-lft

# Main target
all: make_dir $(NAME)
	@echo "$(NAME) ready to use:"

# Rule to create the directories
make_dir:
#	@echo "Creating directories: $(OBJ_DIR) and $(DPS_DIR)"
	@mkdir -p $(OBJ_DIR) $(DPS_DIR)
#	@echo "Done!" && echo ""

# Rule to compile source files to object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | make_dir
	@echo "Compiling $< to $@"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	@mv $(basename $@).d $(DPS_DIR)
#	@echo "Done!" && echo ""


# Rule to build the executable
$(NAME): $(OBJ)
	@echo "Compiling $(NAME)"
	@$(CC) $(CFLAGS) $(INCS) $(OBJ) -o $(NAME) $(LIB)
	@echo "Created $(NAME) executable" && echo ""

# Rule to clean objects and dependencies
clean:
	@echo "Removing ON $(NAME): objects and dependencies..."
	@rm -rf $(OBJ_DIR) $(DPS_DIR)
	@echo "Done!" && echo ""

# Rule to remove the executable
fclean: clean
	@echo "Removing execute $(NAME)..."
	@rm -f $(NAME)
	@echo "Done!" && echo ""

# Rule to clean and build
re: fclean all

# Include dependencies
-include $(DEPS)

# Phony targets
.PHONY: all make_dir clean fclean re
