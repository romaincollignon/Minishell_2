/*
** EPITECH PROJECT, 2022
** write_error.c
** File description:
** Function : write_error
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

#include "../../include/struct_all.h"
#include "my.h"

int error_env(char *str_1, char *str_2, char *str_3)
{
    write(2, str_1, my_strlen(str_1));
    char *tmp_str = malloc(sizeof(char) * 3);
    tmp_str[0] = str_2[5];
    tmp_str[1] = '\0';
    write(2, tmp_str, my_strlen(str_2));
    write(2, str_3, my_strlen(str_3));
    write(2, "Try 'env --help' for more information.\n", 39);
    free(tmp_str);
    return 1;
}

int three_write(char *str_1, char *str_2, char *str_3)
{
    write(2, str_1, my_strlen(str_1));
    write(2, str_2, my_strlen(str_2));
    write(2, str_3, my_strlen(str_3));
    return 0;
}

int double_write(char *str_1, char *str_2)
{
    write(2, str_1, my_strlen(str_1));
    write(2, str_2, my_strlen(str_2));
    return 0;
}

int write_error(char const *str)
{
    write(2, str, my_strlen(str));
    return 0;
}

int write_error_rep(char const *str)
{
    write(2, str, my_strlen(str));
    return 1;
}
