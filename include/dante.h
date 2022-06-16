/*
** EPITECH PROJECT, 2022
** dante
** File description:
** dante
*/

#ifndef dante_
    #define dante_
    #include <unistd.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <ncurses.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <criterion/criterion.h>
    #include <criterion/redirect.h>
    #include <string.h>

typedef struct map_s {
    int height;
    int width;
    char **map;
} map_t;

int redirect_generator(int ar, char **av);
int redirect_solver(int ar, char **av);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_putchar(char c);
char **way(int row, int cols, char **maze, int nbr);
char **change_maze(char **maze, int x, int y, int i);
int generator_imperfect(char *x, char *y);
int generator_perfect(char *x, char *y, char *perfect);
char **split_str(char const *str);
char **alloc(char const *str);
int possibilities(char **map, int x, int y);
int find_j(char **map);
int my_strlen(char const *str);
int find_i(char **map);
char *open_file(char *filepath);
char **rm_triangle(char **maze, int x, int y, int i);
void solv(map_t *map);
int start_way(int x, int y, map_t *info, int i);
int go_right(int x, int y, map_t *info, int i);
int go_left(int x, int y, map_t *info, int i);
int go_down(int x, int y, map_t *info, int i);
int go_up(int x, int y, map_t *info, int i);

#endif /* !dante_ */
