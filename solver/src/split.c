/*
** EPITECH PROJECT, 2022
** split
** File description:
** split
*/

#include "../../include/dante.h"

int skip_space(char const *str, int j)
{
    int i;

    for (i = j; str[i] != ' ' && str[i] != '\t' && str[i] != '\n'; i++);
    for (; str[i] == ' ' || str[i] == '\t' || str[i] == '\n'; i++);
    return (i - 1);
}

int number_column(int a, int b)
{
    return ((a > b) ? a : b);
}

char **fill(char const *str, int cols, int rows)
{
    char **tab;
    int x = 0;
    int y = 0;

    tab = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++)
        tab[i] = malloc(cols * sizeof(char));
    for (int i = 0; str[i] != '\0'; i++, x++) {
        if (str[i] != '\n');
        else {
            x = -1;
            y++;
            i = skip_space(str, i);
        }
        tab[y][x] = str[i];
    }
    return tab;
}

char **split_str(char const *str)
{
    int nb_rows = 0;
    int len = 0;
    int nb_cols = 0;
    char **tab;

    for (int i = 0; str[i] != '\0'; i++, len++) {
        if (str[i] != '\n');
        else {
            nb_cols = number_column(len, nb_cols);
            len = 0;
            nb_rows++;
            i = skip_space(str, i);
        }
    }
    tab = fill(str, nb_cols, nb_rows + 1);
    tab[nb_rows + 1] = NULL;
    return tab;
}
