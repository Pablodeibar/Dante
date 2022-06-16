/*
** EPITECH PROJECT, 2022
** src/
** File description:
** moves
*/

#include "../../include/dante.h"

int go_right(int x, int y, map_t *info, int i)
{
    if (x + 1 < info->width && info->map[y][x + 1] == '*') {
        if (start_way(x + 1, y, info, i + 1) == 0)
            return (0);
    }
}

int go_left(int x, int y, map_t *info, int i)
{
    if (x - 1 >= 0 && info->map[y][x - 1] == '*') {
        if (start_way(x - 1, y, info, i + 1) == 0)
            return (0);
    }
}

int go_down(int x, int y, map_t *info, int i)
{
    if (y + 1 < info->height && info->map[y + 1][x] == '*') {
        if (start_way(x, y + 1, info, i + 1) == 0)
            return (0);
    }
}

int go_up(int x, int y, map_t *info, int i)
{
    if (y - 1 >= 0 && info->map[y - 1][x] == '*') {
        if (start_way(x, y - 1, info, i + 1) == 0)
            return (0);
    }
}
