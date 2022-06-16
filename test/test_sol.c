/*
** EPITECH PROJECT, 2022
** test
** File description:
** test for the solver
*/

#include "../include/dante.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

/*LINKED LIST*/

Test(ini, création_linked_list)
{
    Liste_t *list = ini();

    cr_assert_eq(list->premier->nombre , 0);
}

Test(add_head, création_tête)
{
    Liste_t *list = ini();
    add_head(list, 3);

    cr_assert_eq(list->premier->nombre , 3);
}

Test(display_list, voire_liste, .init = redirect_all_std)
{
    Liste_t *list = ini();
    display_list(list);

    cr_assert_stdout_eq_str("0 ");
}

/*END LINKED LIST*/

/*OPEN FILE*/

Test(open_file, ouvrir_fichier)
{
    char *file = open_file("test/fichier");
    cr_assert_str_eq(file, "voici un fichier");
}

/*END OPEN FILE*/



/* MOVES */

Test(right, droite_no)
{
    char **map = split_str("test/map_test");
    Liste_t *list = ini();
    int response = right(map, 0, 0, list);

    cr_assert_eq(response, 0);
}       

Test(right, droite_yes)
{
    char **map = split_str(open_file("test/map_test"));
    Liste_t *list = ini();
    int response = right(map, 0, 1, list);

    cr_assert_eq(response, 0);
}

Test(right, droite_yes)
{
    char **map = split_str(open_file("test/map_test_2"));
    Liste_t *list = ini();
    int response = right(map, 0, 0, list);

    cr_assert_eq(response, 1);
}

Test(left, gauche_no)
{
    char **map = split_str(open_file("test/map_test_2"));
    Liste_t *list = ini();
    int response = left(map, 0, 0, list);

    cr_assert_eq(response, 0);
}

Test(left, gauche_yes)
{
    char **map = split_str(open_file("test/map_test_2"));
    Liste_t *list = ini();
    int response = left(map, 2, 3, list);

    cr_assert_eq(response, 1);
}

Test(up, haut_no)
{
    char **map = split_str(open_file("test/map_test_2"));
    Liste_t *list = ini();
    int response = up(map, 0, 3, list);

    cr_assert_eq(response, 0);
}

Test(up, haut_yes)
{
    char **map = split_str(open_file("test/map_test_2"));
    Liste_t *list = ini();
    int response = up(map, 1, 1, list);

    cr_assert_eq(response, 1);
}

Test(down, bas_yes)
{
    char **map = split_str(open_file("test/map_test_2"));
    Liste_t *list = ini();
    int response = down(map, 0, 2, list);

    cr_assert_eq(response, 1);
}

Test(possibilities, x)
{
    char **map = split_str(open_file("test/map_test"));
    int response = possibilities(map, 6, 1);

    cr_assert_eq(response, 1);
}

Test(possibilities, y)
{
    char **map = split_str(open_file("test/map_test"));
    int response = possibilities(map, 0, 3);

    cr_assert_eq(response, 1);
}

Test(possibilities, y_2)
{
    char **map = split_str(open_file("test/map_test"));
    int response = possibilities(map, 7, 4);

    cr_assert_eq(response, 1);
}

/*
Test(down, bas_no)
{
    char **map = split_str(open_file("test/map_test_2"));
    Liste_t *list = ini();
    int response = down(map, 7, 2, list);

    cr_assert_eq(response, 0);
}*/

/* END MOVES*/

/* NBR COLS */

Test(find_i, trois)
{
    char **map = split_str(open_file("test/map_test_2"));
    int response = find_i(map);

    cr_assert_eq(response, 6);
}

Test(find_j, deux)
{
    char **map = split_str(open_file("test/map_test_2"));
    int response = find_j(map);

    cr_assert_eq(response, 9);
}
/*
Test(return_elem, elem)
{
    char **map = split_str(open_file("test/map_test_2"));
    Liste_t *list = ini();
    add_end(list, map, 3, 3);
    int occ = 1;
    element_t *test = return_elem(occ, list);

    cr_assert_eq(test->x, 2);
}
*/
/* END SOLVER */

/* CLASSIC */

Test(my_putchar, char_, .init = redirect_all_std)
{
    my_putchar('a');
    cr_assert_stdout_eq_str("a");
}

Test(my_put_nbr, char_, .init = redirect_all_std)
{
    my_put_nbr(56);
    cr_assert_stdout_eq_str("56");
}

Test(my_putstr, char_, .init = redirect_all_std)
{
    my_putstr("bonjour");
    cr_assert_stdout_eq_str("bonjour");
}

/* END CLASSIC */

/* MAIN LOOP */

Test(move_x, simple)
{
    char **map = split_str(open_file("test/map_test_2"));
    Liste_t *list = ini();
    int response = move_x(map, 0, 0, list);

    cr_assert_eq(response, 1);
}

Test(move_x, simple_2)
{
    char **map = split_str(open_file("test/map_test_2"));
    Liste_t *list = ini();
    int response = move_x(map, 8, 0, list);

    cr_assert_eq(response, 7);
}

Test(move_y, simple)
{
    char **map = split_str(open_file("test/map_test_2"));
    Liste_t *list = ini();
    int response = move_y(map, 0, 0, list);

    cr_assert_eq(response, 1);
}

Test(move_y, simple_2)
{
    char **map = split_str(open_file("test/map_test_2"));
    Liste_t *list = ini();
    int response = move_y(map, 5, 5, list);

    cr_assert_eq(response, 4);
}

/* END MAIN LOOP */
