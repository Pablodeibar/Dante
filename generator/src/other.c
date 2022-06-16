/*
** EPITECH PROJECT, 2022
** generator
** File description:
** generator
*/

#include "../../include/dante.h"

char **way(int cols, int row, char **maze, int nbr)
{
    static int x = 0;
    static int y = 0;

    if (nbr == 1) {
        x = 0;
        y = 0;
    }
    maze[x][y] = '*';
    if (rand() % 2 == 1) {
        if (y + 1 >= cols)
            x++;
        else
            y++;
    } else {
        if (x + 1 >= row)
            y++;
        else
            x++;
    }
    return maze;
}

int number_wall(char **maze, int *coo, int i, int j)
{
    int wall = 0;

    if (i != 0 && maze[i - 1][j] == '*') {
        wall++;
    }
    if (i < coo[0] - 1 && maze[i + 1][j] == '*') {
        wall++;
    }
    if (j > 0 && maze[i][j - 1] == '*') {
        wall++;
    }
    if (j != coo[1] && maze[i][j + 1] == '*') {
        wall++;
    }
    return wall;
}

char **other(char **maze, int i, int j, int *coo)
{
    if (maze[i][j] == '*') {
    } else if (number_wall(maze, coo, i, j) != 1) {
        maze[i][j] = 'X';
    } else {
        if ((rand() % (coo[0] * coo[1])) < ((coo[0] * coo[1]) / 50 * 100)) {
            maze[i][j] = '*';
        } else {
            maze[i][j] = 'X';
        }
    }
    return maze;
}

char **change_maze(char **maze, int x, int y, int i)
{
    int coo[2] = {y, x};

    for (int j = 0; maze[i][j] != '\0'; j++) {
        other(maze, i, j, coo);
    }
    return maze;
}
