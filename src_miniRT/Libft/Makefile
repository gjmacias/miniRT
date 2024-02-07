# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 19:51:17 by ffornes-          #+#    #+#              #
#    Updated: 2023/09/27 16:14:24 by laugarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES = include/

###############################################################################
#									SRCS									  #
###############################################################################

SRCS_LIBFT_DIR = srcs/
SRC_FILES =	 ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			 ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			 ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			 ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			 ft_atoi.c ft_calloc.c ft_strdup.c ft_strdup.c ft_substr.c \
			 ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			 ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			 ft_putnbr_fd.c \
			 ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			 ft_lstmap.c \
			 ft_delete.c ft_lstpos.c ft_atoi_base.c free_double.c ft_atoll.c 

SRCS_LIBFT = $(addprefix $(SRCS_LIBFT_DIR), $(SRC_FILES))

SRCS_GNL_DIR = get_next_line/
SRC_GNL_FILES =	get_next_line.c
SRCS_GNL = $(addprefix $(SRCS_GNL_DIR), $(SRC_GNL_FILES))

###############################################################################
#									OBJS									  #
###############################################################################

OBJS_LIBFT_DIR =	objs/
OBJ_LIBFT_FILES =	$(SRC_FILES:.c=.o)
OBJS_LIBFT = $(addprefix $(OBJS_LIBFT_DIR), $(OBJ_LIBFT_FILES))

OBJS_GNL_DIR =	get_next_line/objs/
OBJ_GNL_FILES = $(SRC_GNL_FILES:.c=.o)
OBJS_GNL = $(addprefix $(OBJS_GNL_DIR), $(OBJ_GNL_FILES))

OBJS = $(OBJS_LIBFT) $(OBJS_GNL)

###############################################################################
#									DEPS									  #
###############################################################################

DEP_LIBFT_FILES = $(SRC_FILES:.c=.d)
DEP_GNL_FILES = $(SRC_GNL_FILES:.c=.d)

DEPS_LIBFT = $(addprefix $(OBJS_LIBFT_DIR), $(DEP_LIBFT_FILES))
DEPS_GNL = $(addprefix $(OBJS_GNL_DIR), $(DEP_GNL_FILES))

DEPS = $(DEPS_LIBFT) $(DEPS_GNL)

###############################################################################
#									OTHER									  #
###############################################################################

CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD
RM = rm -f
AR = ar rc

INCLUDE = -I include/

###############################################################################
#									RULES									  #
###############################################################################

all: 		$(NAME)

$(NAME):	$(OBJS_LIBFT_DIR) $(OBJS_GNL_DIR) $(OBJS)
			$(AR) $@ $(OBJS)

$(OBJS_LIBFT_DIR):		
						@mkdir $(OBJS_LIBFT_DIR)

$(OBJS_GNL_DIR):
						@mkdir $(OBJS_GNL_DIR)

$(OBJS_LIBFT_DIR)%.o:	$(SRCS_LIBFT_DIR)%.c
						$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJS_GNL_DIR)%.o:		$(SRCS_GNL_DIR)%.c
						$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean: 		
			@$(RM) $(OBJS) $(DEPS)

fclean: 	clean
			@$(RM) $(NAME)

re:			fclean all

-include $(DEPS)

.PHONY: all clean fclean re
