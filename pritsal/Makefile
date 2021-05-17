
NAME = libftprintf.a

CC = cc
C_FLAGS = -Wall -Wextra -Werror

LFT_PATH = ./libraries/
OBJ_PATH = ./objs/
INC_PATH = ./includes/
SRC_PATH = ./srcs/

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_NAME_BNS = $(SRC_BONUS:.c=.o)
INC_NAME = libftprintf.h
SRC_NAME = ft_printf.c ft_search.c ft_format_c.c ft_format_s.c \
	   ft_format_int.c ft_format_uint.c ft_format_percent.c \
	   ft_flag_min.c ft_flag_number.c ft_flag_asterisk.c \
	   ft_flag_zero.c ft_flag_prec.c

SRC_BONUS = ft_getdbl_bonus.c ft_getdbl_exponent_bonus.c \
	   ft_getdbl_fraction_bonus.c ft_flag_hash_bonus.c \
	   ft_flag_plus_bonus.c ft_flag_spc_bonus.c ft_format_e_bonus.c \
	   ft_format_f_bonus.c ft_format_g_bonus.c ft_format_h_int_bonus.c \
	   ft_format_h_uint_bonus.c ft_format_hh_int_bonus.c \
	   ft_format_hh_uint_bonus.c ft_format_n_bonus.c \
	   ft_dbl_case_e_bonus.c ft_dbl_case_f_bonus.c ft_round_dbl_bonus.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
SRC_BNS = $(addprefix $(SRC_PATH),$(SRC_BONUS))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
OBJ_BNS = $(addprefix $(OBJ_PATH), $(OBJ_NAME_BNS))
INC = $(addprefix -I,$(INC_PATH)) $(addprefix -I,$(LFT_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_PATH)
	@ar rc $@ $(OBJ)
	@libtool -static -o $@ $@ $(LFT_PATH)libft.a
	@ranlib $@
	@echo "Obj folder & files created"
	@echo "Executable created"
	@echo "Compilation finished"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(OBJ_PATH)
	@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

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

bonus: $(OBJ) $(OBJ_BNS)
	@make -C $(LFT_PATH)
	@ar rc $(NAME) $(OBJ) $(OBJ_BNS)
	@libtool -static -o $(NAME) $(NAME) $(LFT_PATH)libft.a
	@ranlib $(NAME)
	@echo "Obj folder & files created"
	@echo "Executable created"
	@echo "Compilation finished"

norme:
	@norminette -R CheckForbiddenSourceHeader $(SRC)
	@echo "C files norme check finished"
	@norminette -R CheckDefine $(INC_PATH)
	@echo "Header files norme check finished"
