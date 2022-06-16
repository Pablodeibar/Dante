/*
** EPITECH PROJECT, 2022
** solver
** File description:
** solver
*/

#include "../../include/dante.h"

void print(map_t *info)
{
    for (int i = 0; i != info->height; i++) {
        my_putstr(info->map[i]);
        my_putchar('\n');
    }
}

int verif_max(int x, int y, map_t *info)
{
    if (x == info->width - 1 && y == info->height - 1)
        return (1);
}

int start_way(int x, int y, map_t *info, int i)
{
    info->map[y][x] = 'o';
    if (verif_max(x, y, info) == 1)
        return (0);
    if (go_right(x, y, info, i) == 0)
        return (0);
    if (go_down(x, y, info, i) == 0)
        return (0);
    if (go_left(x, y, info, i) == 0)
        return (0);
    if (go_up(x, y, info, i) == 0)
        return (0);
    info->map[y][x] = '-';
    return (1);
}

void bad_way(map_t *info, int y, int x)
{
    if (info->map[y][x] == '-')
        info->map[y][x] = '*';
}

void solv(map_t *info)
{
    int x;
    int y;

    for (y = 0; y != info->height; y++) {
        for (int x = 0; x != info->width; x++) {
            bad_way(info, y, x);
        }
    }
    print(info);
}
