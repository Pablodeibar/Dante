/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void minimum(void)
{
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    } else if (nb == -2147483648) {
        minimum();
    }
}

int my_putstr(char const *str)
{
    int compter = 0;

    while (str[compter] != '\0') {
        my_putchar(str[compter]);
        compter++;
    }
}

int my_strlen(char const *str)
{
    int compteur = 0;

    while (str[compteur] != '\0') {
        compteur++;
    }
    return (compteur);
}
