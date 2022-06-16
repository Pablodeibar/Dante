/*
** EPITECH PROJECT, 2022
** main_function
** File description:
** main_functions
*/

#include "../../include/dante.h"

char *open_file(char *filepath)
{
    int i = open(filepath, O_RDONLY);
    struct stat sb;
    char *str;

    stat(filepath, &sb);
    str = malloc(sizeof(char) * (sb.st_size + 1));
    read(i, str, sb.st_size);
    close(i);
    str[sb.st_size] = '\0';
    return (str);
}

void fill_struct(map_t *info, char *map)
{
    int i = 0;

    info->map = split_str(map);
    info->height = 0;
    info->width = 0;
    for (; info->map[i] != NULL; i++);
    info->height = i;
    for (i = 0; info->map[0][i] != '\0'; i++);
    info->width = i;
}

void free_struct(map_t *info)
{
    free(info->map[1]);
    /*
    for (int i = 0; i != 1; i++) {
        my_put_nbr(i);
        my_putstr(info->map[i]);
        free(info->map[i]);
    }*/
    //free(info->map);
}

int redirect_solver(int ar, char **av)
{
    char *map_file = open_file(av[1]);
    map_t info;

    fill_struct(&info, map_file);
    if (start_way(0, 0, &info, 0) == 1) {
        my_putstr("no solution found\n");
        return (0);
    }
    solv(&info);
   //free_struct(&info);
}
