# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgrea <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/20 16:19:36 by fgrea             #+#    #+#              #
#    Updated: 2017/04/25 18:13:50 by fgrea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

ifneq ($(shell make -q -C libft; echo $$?), 0)
	.PHONY: libft/libft.a
endif

NAME = libftprintf.a

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

cc = gcc
C_FLAGS = -Wall -Wextra -Werror
TEMP = .temp.a

OBJ_PATH = ./obj/
LFT_PATH = ./libft/
INC_PATH = ./includes/
SRC_PATH = ./srcs/

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = ft_printf.h
SRC_NAME =	ft_printf.c					\
			ft_parse.c					\
			ft_parse_conv.c				\
			ft_parse_flag.c				\
			ft_parse_size.c				\
			ft_parse_precision.c		\
			ft_parse_modif.c			\
			ft_reader.c					\
			ft_write_arg.c				\
			ft_write_c.c				\
			ft_write_wc.c				\
			ft_write_sgn.c				\
			ft_write_sgn_pos.c			\
			ft_write_sgn_neg.c			\
			ft_write_octal.c			\
			ft_write_b.c				\
			ft_write_p.c				\
			ft_write_s.c				\
			ft_write_ws.c				\
			ft_write_uns.c				\
			ft_write_hexa.c				\
			ft_write_non_valid.c		\
			ft_write_flag.c				\
			ft_printf_putnbr_uns.c		\
			ft_printf_nbrlen_uns.c		\
			ft_printf_str.c				\
			ft_caste_sgn.c				\
			ft_caste_uns.c				\

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
			@make -C $(LFT_PATH)
			@ar rc $(TEMP) $(OBJ)
			@libtool -static -o $(NAME) $(TEMP) $(LIB)
			@ranlib $(NAME)
			@echo "$(OKC)$(NAME):\t\tCOMPILED$(NOC)"
			@echo "***************************************"
			@echo "----------------__---------------------"
			@echo "--------------<(o )___.----------------"
			@echo "---------------( ._> /-----------------"
			@echo "----------------\`---'-------C.WC------"
			@echo "***************************************"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
			@mkdir -p $(OBJ_PATH) 2> /dev/null || true
			@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<

clean:
			@make -C $(LFT_PATH) clean
			@rm -rf $(OBJ_PATH)
			@echo "$(WAC)$(NAME):\t\tCLEANING OBJS$(NOC)"
			@echo "***************************************"


fclean: clean
			@make -C $(LFT_PATH) fclean
			@rm -f $(NAME) $(TEMP)
			@echo "$(WAC)$(NAME):\t\tCOMPILATION TRACES REMOVED$(NOC)"
			@echo "***************************************"


re: fclean
			@$(MAKE) all
