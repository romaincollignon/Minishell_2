/*
** EPITECH PROJECT, 2022
** my_unsetenv.c
** File description:
** Function : unsetenv
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../../include/struct_all.h"
#include "../../include/my.h"

int suppr_env(i_s* info_shell, char **tab_cmd, int pos_cmd)
{
    int pos = cherch_arg_env(info_shell, tab_cmd[pos_cmd]);
    if (pos == -1)
        return 0;
    for (; pos < info_shell->size_env; pos++)
        info_shell->env[pos] = info_shell->env[pos + 1];
    info_shell->env[pos] = NULL;
    info_shell->size_env--;
    return 0;
}

int suppr_env_several(i_s *info_shell, char **tab_cmd, int tmp_nb_arg)
{
    tmp_nb_arg--;
    for (; tmp_nb_arg > 0; tmp_nb_arg--)
        suppr_env(info_shell, tab_cmd, tmp_nb_arg);
    return 0;
}

int my_unsetenv(i_s *info_shell, char *cmd)
{
    int tmp_nb_arg = nb_arg(cmd);
    if (tmp_nb_arg == 1){
        write_error("unsetenv: Too few arguments.\n");
        return 0;
    }
    char **tab_cmd = my_str_to_word_array(cmd, " ");
    if (tmp_nb_arg == 2) {
        return suppr_env(info_shell, tab_cmd, 1);
    } else {
        return suppr_env_several(info_shell, tab_cmd, tmp_nb_arg);
    } return 0;
}
