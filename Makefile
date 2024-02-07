RESET=\033[0m
BOLD=\033[1m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m

BG_RED=\033[41m
BG_GREEN=\033[42m
BG_YELLOW=\033[43m
BG_BLUE=\033[44m
BG_MAGENTA=\033[45m
BG_CYAN=\033[46m
BG_WHITE=\033[47m

CC = cc
OFALGS = -Wall -Wextra -Werror
CFALGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
NAME = so_long
BNAME = so_long_bonus
LIBDIR = mandatory/libft-custom
BLIBDIR = bonus/libft-custom
LIB = libft.a
INC = -I$(LIBDIR) -L$(LIBDIR) -lft
BINC = -I$(BLIBDIR) -L$(BLIBDIR) -lft
SRC = mandatory/source/main.c mandatory/source/parser.c mandatory/source/utils.c mandatory/source/way_to_win.c \
	mandatory/source/so_long.c mandatory/source/moves.c mandatory/source/utils2.c

BSRC = bonus/source/main_bonus.c bonus/source/parser_bonus.c bonus/source/utils_bonus.c bonus/source/way_to_win_bonus.c \
	bonus/source/so_long_bonus.c bonus/source/moves_bonus.c bonus/source/utils2_bonus.c bonus/source/utils3_bonus.c bonus/source/utils4_bonus.c \
	bonus/source/utils5_bonus.c

HEADERS = mandatory/libft-custom/get_next_line.h mandatory/libft-custom/libft.h mandatory/so_long.h

BHEADERS = bonus/libft-custom/get_next_line.h bonus/libft-custom/libft.h bonus/so_long_bonus.h

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

all : $(NAME)
bonus : $(BNAME)

$(NAME) : $(OBJ) mk_lib
	@echo "$(BG_YELLOW)$(BOLD)object files generated $(RESET)"
	@echo "$(YELLOW)building executable...$(RESET)"
	@$(CC) $(CFALGS) $(OBJ) $(INC) -o $(NAME)
	@echo "$(BG_GREEN)ready to use $(RESET)"
$(BNAME) : $(BOBJ) mk_lib_bonus
	@echo "$(BG_YELLOW)$(BOLD)object files generated $(RESET)"
	@echo "$(YELLOW)building executable...$(RESET)"
	@$(CC) $(CFALGS) $(BOBJ) $(BINC) -o $(BNAME)
	@echo "$(BG_GREEN)ready to use $(RESET)"

%.o : %.c $(HEADERS)
	@$(CC) $(OFALGS) -c $< -o $@

%_bonus.o : %_bonus.c $(BHEADERS)
	@$(CC) $(OFALGS) -c $< -o $@

mk_lib : $(HEADERS)
	@make -C $(LIBDIR)
	@echo "$(GREEN)making custom-lib$(RESET)"

mk_lib_bonus : $(BHEADERS)
	@make -C $(BLIBDIR)
	@echo "$(GREEN)making custom-lib$(RESET)"

clean :
	@echo "$(RED)removing object files...$(RESET)"
	@make -C $(LIBDIR) clean
	@make -C $(BLIBDIR) clean
	@$(RM) $(OBJ) $(BOBJ)
	@echo "$(BG_RED)object files removed$(RESET)"

fclean : clean
	@echo "$(RED)removing executable...$(RESET)"
	@make -C $(LIBDIR) fclean
	@make -C $(BLIBDIR) fclean
	@$(RM) $(NAME) $(BNAME)
	@echo "$(BG_RED)xecutable removed$(RESET)"

re : fclean all

.PHONY : clean mk_lib mk_lib_bonus