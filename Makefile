##
## EPITECH PROJECT, 2022
## make
## File description:
## make
##

SRC_TESTS = 					solver/src/move.c				\
								solver/src/linke_list.c			\
								solver/src/main_functions.c		\
								solver/src/my_put.c				\
								solver/src/resolve.c			\
								solver/src/split.c				\
								solver/src/number_cols.c		\
								test/test_sol.c					\

CLEANFOL					=	make clean

FCLEANFOL					=	make fclean

NAME_TEST	=	unit_test

CC							=	gcc

TEST_FLAGS	=	--coverage -lcriterion

all:
								$(MAKE) -C generator/
								$(MAKE) -C solver/

tests_run:
			$(CC) -o $(NAME_TEST) $(SRC_TESTS) $(TEST_FLAGS)
			./$(NAME_TEST)
			gcovr

clean:
								$(CLEANFOL) -C generator/
								$(CLEANFOL) -C solver/

fclean:
								$(FCLEANFOL) -C generator/
								$(FCLEANFOL) -C solver/
								rm *.gcno
								rm *.gcda
								rm unit_test

re:
								fclean all

.PHONY						=	all clean fclean re