# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgrea <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 10:59:04 by fgrea             #+#    #+#              #
#    Updated: 2020/11/28 13:41:29 by fgrea            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = pintf

CC = cc
C_FLAGS = -Wall -Wextra -Werror

LFT_PATH = ./libraries/libft/
LFT_INC_PATH = ./libraries/libft/includes/
OBJ_PATH = ./objs/
INC_PATH = ./includes/
SRC_PATH = ./srcs/

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = libftprintf.h
SRC_NAME = ft_printf.c 

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH)) $(addprefix -I,$(LFT_INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
						@make -C $(LFT_PATH)
						@$(CC) -L $(LFT_PATH) -lft -o $@ $(OBJ)
						#@ranlib $@
						@echo "Obj folder & files created"
						@echo "Executable created"
						@echo "Compilation finished"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
						@mkdir $(OBJ_PATH) 2> /dev/null || true
						@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<

clean:
						@make clean -C $(LFT_PATH)
						@rm -rf $(OBJ_PATH) 2> /dev/null || true
						@echo "Obj folder & files suppressed"

fclean: clean
						@make fclean -C $(LFT_PATH)
						@rm -f $(NAME)
						@echo "Executable suppressed"

re: fclean
						@$(MAKE) all

norme:
						@norminette -R CheckForbiddenSourceHeader $(SRC)
						@echo "C files norme check finished"
						@norminette -R CheckDefine $(INC_PATH)
						@echo "Header files norme check finished"
