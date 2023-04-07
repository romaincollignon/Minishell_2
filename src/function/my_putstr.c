/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** taks02
*/

#include <unistd.h>

void my_putchar(char c);

int my_strlen(char const *str)
{
    int n = 0;
    while (str[n] != '\0') {
        n = n + 1;
    }
    return n;
}

int my_putstr(char const *str)
{
    return write(1, str, my_strlen(str));
}
