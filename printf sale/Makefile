# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edassess <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 10:35:23 by edassess          #+#    #+#              #
#    Updated: 2021/05/17 10:35:32 by edassess         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_printf.c ft_search.c ft_format_c.c ft_format_s.c \
	   ft_format_int.c ft_format_uint.c ft_format_percent.c ft_flag_min.c \
	   ft_flag_number.c ft_flag_asterisk.c ft_flag_zero.c ft_flag_prec.c
OBJS			= $(SRCS:.c=.o)

BONUS			= ft_getdbl_bonus.c ft_getdbl_exponent_bonus.c \
	 ft_getdbl_fraction_bonus.c ft_flag_hash_bonus.c \
	 ft_flag_plus_bonus.c ft_flag_spc_bonus.c ft_format_e_bonus.c \
	 ft_format_f_bonus.c ft_format_g_bonus.c ft_format_h_int_bonus.c \
	 ft_format_h_uint_bonus.c ft_format_hh_int_bonus.c \
	 ft_format_hh_uint_bonus.c ft_format_n_bonus.c \
	 ft_dbl_case_e_bonus.c ft_dbl_case_f_bonus.c ft_round_dbl_bonus.c

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= @gcc
RM				= @rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
