/*
* EPITECH PROJECT, 2022
** generator
** File description:
** generator
*/

#include "../../include/dante.h"
#include <time.h>

char **create_maze_perfect(char **maze, int x, int y)
{
    for (int i = 0; y != i; i++) {
        for (int j = 0; j != x; j++) {
            maze[i][j] = '.';
        }
        maze[i][x] = '\0';
    }
    maze[y] = NULL;
    while (x == 0 || y == 0 || maze[y - 1][x - 1] != '*') {
        way(x, y, maze, 0);
    }
    for (int i = 0; y != i; i++) {
        change_maze(maze, x, y, i);
    }
}

char **create_maze_imperfect(char **maze, int x, int y, int l)
{
    for (int i = 0; y != i; i++) {
        for (int j = 0; j != x; j++) {
            maze[i][j] = '.';
        }
        maze[i][x] = '\0';
    }
    maze[y] = NULL;
    while (x == 0 || y == 0 || maze[y - 1][x - 1] != '*') {
        way(x, y, maze, 0);
    }
    maze[y - 1][x - 1] = '.';
    while (x == 0 || y == 0 || maze[y - 1][x - 1] != '*') {
        way(x, y, maze, l);
        l++;
    }
    for (int i = 0; y != i; i++) {
        change_maze(maze, x, y, i);
    }
    return maze;
}

void print_maze(char **maze, int x, int y)
{
    for (int i = 0; y - 1 != i; i++) {
        write(1, maze[i], x);
        write(1, "\n", 1);
    }
    write(1, maze[y - 1], x);
}

int generator_imperfect(char *x_str, char *y_str)
{
    int x = atoi(x_str);
    int y = atoi(y_str);
    char **maze;
    int l = 1;

    srand(time(NULL));
    if (x <= 1 || y <= 1)
        return 84;
    maze = malloc(sizeof(char *) * (y + 1));
    for (int i = 0; i < y; i++) {
        maze[i] = malloc(sizeof(char) * (x + 1));
        if (maze[i] == NULL)
            return 84;
    }
    create_maze_imperfect(maze, x, y, l);
    print_maze(maze, x, y);
    for (int i = 0; i != (y + 1); i++) {
        free(maze[i]);
    }
    free(maze);
}

int generator_perfect(char *x_str, char *y_str, char *perfect)
{
    int x = atoi(x_str);
    int y = atoi(y_str);
    char **maze;

    srand(time(NULL));
    if (x <= 1 || y <= 1 || strcmp("perfect", perfect) != 0)
        return 84;
    maze = malloc(sizeof(char *) * (y + 1));
    for (int i = 0; i < y; i++) {
        maze[i] = malloc(sizeof(char) * (x + 1));
        if (maze[i] == NULL)
            return 84;
    }
    create_maze_perfect(maze, x, y);
    print_maze(maze, x, y);
    for (int i = 0; i != (y + 1); i++) {
        free(maze[i]);
    }
    free(maze);
}
