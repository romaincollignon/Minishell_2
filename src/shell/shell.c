/*
** EPITECH PROJECT, 2022
** shell.c
** File description:
** Function : shell
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../../include/struct_all.h"
#include "my.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_piped(char *cmd)
{
    for (int n = 0; cmd[n] != '\0'; n++) {
        if (cmd[n] == '|')
            return 1;
    }
    return 0;
}

void start_shell(i_s *info_shell, char *cmd)
{
    int error;
    if (is_piped(cmd) == 1) {
        error = main_pipe(info_shell, cmd);
        error_shell(info_shell, error);
    } else {
        info_shell->st_pipe.pos = 0;
        info_shell->st_pipe.nb_pipe = 0;
        info_shell->st_pipe.pos_max = 0;
        error = start_cmd(info_shell, cmd);
        error_shell(info_shell, error);
    }
    if (info_shell->st_redi.redir_type[1] == 1)
        reset_int_double(info_shell);
    if (info_shell->st_redi.redir_type[0] == 1)
        reset_int_single(info_shell);
    stop_redirect(info_shell);
    reset_redirect(info_shell);
}

void suite_shell(i_s *info_shell, char *cmd)
{
    info_shell->st_redi.err_redir = 0;
    int error_redir = redirect_error(info_shell, cmd);
    if (error_redir == 1) {
        return;
    } else {
        if (start_redirect(info_shell, cmd) == 84) {
            return;
        }
    }
    start_shell(info_shell, cmd);
}

int boucle_shell(i_s *info_shell, int error)
{
    print_deb();
    signal(SIGINT, sigint_signal_gesture);
    char *cmd = get_cmd(info_shell);
    if (info_shell->stop == 1)
        return 0;
    if (cmd[0] == '\n')
        return 0;
    if (cleaner_and_patch(cmd) == 1)
        return 0;
    char **tab_cmd = my_str_to_word_array(cmd, ";\n");
    for (int n = 0; tab_cmd[n] != NULL; n++) {
        reset_redirect(info_shell);
        if (verif_espace(tab_cmd[n]) == 1) {
            continue;
        }
        tab_cmd[n] = my_cleaner(tab_cmd[n]);
        info_shell->st_pipe.nb_pipe = 0;
        suite_shell(info_shell, tab_cmd[n]);
    }
    return 0;
}

int shell(i_s *info_shell)
{
    int error = 0;
    while (info_shell->stop == 0) {
        while (info_shell->restart == 0 && info_shell->stop == 0) {
            error = boucle_shell(info_shell, error);
        }
        info_shell->restart = 0;
    } return 0;
}
