##
## EPITECH PROJECT, 2022
## make
## File description:
## make
##

SRC								=	main.c					\
									src/generator.c				\
									src/other.c				\

OBJ								=	$(SRC:%.c=%.o)

OBJ_TEST						=	$(SRC_TEST:%.c=%.o)

NAME							=	generator

CC								=	gcc

MAKE							=	make

CLEANFOL						=	make clean

FCLEAN							=	make fclean

CFLAGS							=	-I./include

TEST_FLAGS						=	-I../include --coverage -lcriterion

all:								$(NAME)
$(NAME):							$(OBJ)
									$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
									rm -f $(OBJ)

fclean:								clean
									rm -f $(NAME)

re:									fclean all

.PHONY							=	all clean fclean re
