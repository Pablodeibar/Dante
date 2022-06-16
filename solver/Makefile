##
## EPITECH PROJECT, 2022
## make
## File description:
## make
##

SRC								=	main.c							\
									src/main_functions.c			\
									src/my_put.c					\
									src/split.c						\
									src/solver.c					\
									src/moves.c						\

OBJ								=	$(SRC:%.c=%.o)

OBJ_TEST						=	$(SRC_TEST:%.c=%.o)

NAME							=	solver

CC								=	gcc

MAKE							=	make

CLEANFOL						=	make clean

FCLEAN							=	make fclean

CFLAGS							=	-I./include

TEST_FLAGS						=	-I./include --coverage -lcriterion

all:								$(NAME)
$(NAME):							$(OBJ)
									$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
									make clean

clean:
									rm -f $(OBJ)

fclean:								clean
									rm -f $(NAME)

re:									fclean all

.PHONY							=	all clean fclean re
