/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "../include/dante.h"

int main(int argc, char **argv)
{
    if (argc == 3) {
        generator_imperfect(argv[1], argv[2]);
    } else if (argc == 4) {
        generator_perfect(argv[1], argv[2], argv[3]);
    } else {
        return 84;
    }
}
