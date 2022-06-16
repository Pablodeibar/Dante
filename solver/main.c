/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "../include/dante.h"

int main(int ar, char **av)
{
    if (ar != 2) {
        return (84);
    } else {
        redirect_solver(ar, av);
    }
    return (0);
}
