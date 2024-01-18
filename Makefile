CC = cc
OFALGS = -g -Wall -Wextra -Werror
CFALGS = -lmlx -framework OpenGL -framework AppKit -g
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

BSRC = bonus/source/main.c bonus/source/parser.c bonus/source/utils.c bonus/source/way_to_win.c \
	bonus/source/so_long_bonus.c bonus/source/moves.c bonus/source/utils2.c bonus/source/utils3.c bonus/source/utils4.c \
	bonus/source/enemy.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

all : $(NAME)
bonus : $(BNAME)

$(NAME) : $(OBJ) mk_lib
	$(CC) $(CFALGS) $(OBJ) $(INC) -o $(NAME)
$(BNAME) : $(BOBJ) mk_lib_bonus
	$(CC) $(CFALGS) $(BOBJ) $(BINC) -o $(BNAME)

%.o : %.c
	$(CC) $(OFALGS) -c $< -o $@

mk_lib :
	@make -C $(LIBDIR)
	@echo "making custom-lib"

mk_lib_bonus :
	@make -C $(BLIBDIR)
	@echo "making custom-lib"


clean :
	@make -C $(LIBDIR) clean
	@make -C $(BLIBDIR) clean
	@$(RM) $(OBJ) $(BOBJ)

fclean : clean
	@make -C $(LIBDIR) fclean
	@make -C $(BLIBDIR) fclean
	@$(RM) $(NAME) $(BNAME)

re : fclean all

.PHONY : clean mk_lib mk_lib_bonus