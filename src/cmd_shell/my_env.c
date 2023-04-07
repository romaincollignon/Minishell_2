/*
** EPITECH PROJECT, 2022
** my_env.c
** File description:
** Function : my_env
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../../include/struct_all.h"
#include "../../include/my.h"

char *env_one_arg(char *cmd, int deb)
{
    int n = 0;
    for (int a = deb; cmd[a] != '\0'; a++) {
        cmd[n] = cmd[a];
        n++;
    }
    cmd[n] = '\0';
    return cmd;
}

static char *good_arg_env(char *cmd)
{
    char *result = malloc(sizeof(char) * (my_strlen(cmd) + 5));
    char *f_name = "unsetenv ";
    for (int a = 0; a < 9; a++)
        result[a] = f_name[a];
    char *arg = env_one_arg(cmd, 7);
    int a = 9;
    int n = 0;
    for (; arg[n] != '\0'; n++) {
        result[a] = arg[n];
        a++;
    }
    result[a] = '\0';
    return result;
}

int my_env(i_s *info_shell, char *cmd)
{
    if (cmd[3] == '\0') {
        for (int n = 0; n < info_shell->size_env; n++)
            mini_printf("%s\n", info_shell->env[n]);
        return 0;
    } if ((cmd[3] == ' ' && cmd[4] == '-' && cmd[5] == '0' && cmd[6] == '\0')
    || (cmd[3] == ' ' && cmd[4] == '-' && cmd[5] == '-' && cmd[6] == 'n' &&
    cmd[7] == 'u' && cmd[8] == 'l' && cmd[9] == 'l' && cmd[10] == '\0')) {
        for (int n = 0; info_shell->env[n] != NULL; n++)
            mini_printf("%s", info_shell->env[n]);
        mini_printf("\n");
    } if (cmd[3] == ' ' && cmd[4] == '-' && cmd[5] == 'u' && cmd[6] == '\0') {
        write_error("env: option requires an argument -- 'u'\n");
    } if (cmd[3] == ' ' && cmd[4] == '-' && cmd[5] == 'u' && cmd[6] == ' ') {
        return my_unsetenv(info_shell, good_arg_env(cmd));
    } if (cmd[3] == ' ' && cmd[4] == '-' && cmd[5] != '\0') {
        error_env("env: invalid option -- '", cmd, "'\n");
    } else {
        three_write("env: '", env_one_arg(cmd, 4),
            "':No such file or directory\n");
    } return 0;
}
