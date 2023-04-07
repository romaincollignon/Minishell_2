/*
** EPITECH PROJECT, 2022
** fonction_redirect.c
** File description:
** Function :
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

#include "../../../include/struct_all.h"
#include "my.h"


int redirect_out_single(i_s *info_shell)
{
    info_shell->st_redi.old = dup(STDOUT_FILENO);
    int out_file_fd = open(info_shell->st_redi.redir_file_out,
        O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (out_file_fd == -1) {
        double_write(info_shell->st_redi.redir_file_out,
            ": Permission denied.\n");
        info_shell->st_redi.err_redir = 84;
        return 1;
    } if (out_file_fd == -1) {
        write_error("Error create file.\n");
        return 1;
    }
    if (dup2(out_file_fd, STDOUT_FILENO) == -1) {
        perror(err_one_word(info_shell->st_redi.redir_file_out));
        info_shell->st_redi.err_redir = 84;
        close(out_file_fd);
        return 1;
    }
    close(out_file_fd);
    return 0;
}

void redirect_out_double(i_s *info_shell)
{
    info_shell->st_redi.old = dup(STDOUT_FILENO);
    int out_file_fd = open(info_shell->st_redi.redir_file_out,
        O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (out_file_fd == -1 &&
        access(info_shell->st_redi.redir_file_out, F_OK) == 0) {
        double_write(info_shell->st_redi.redir_file_out,
            ": Permission denied.\n");
        info_shell->st_redi.err_redir = 84;
        return;
    } if (out_file_fd == -1) {
        write_error("Error create file.\n");
        return;
    }
    if (dup2(out_file_fd, STDOUT_FILENO) == -1) {
        perror(err_one_word(info_shell->st_redi.redir_file_out));
        info_shell->st_redi.err_redir = 84;
        close(out_file_fd);
        return;
    }
    close(out_file_fd);
}

char **create_tab_cmd(char *cmd, char **arg)
{
    int size = 0; int a = 0; int n = 0;
    for (; arg[size] != NULL; size++);
    char **tab_cmd = malloc(sizeof(char *) * (size + 2));
    for (; arg[n] != NULL; n++) {
        tab_cmd[n] = malloc(sizeof(char) * (my_strlen(cmd) + my_strlen(arg[n]) +
            5));
        a = 0;
        for (; cmd[a] != '\0'; a++)
            tab_cmd[n][a] = cmd[a];
        tab_cmd[n][a] = ' ';
        a++;
        for (int i = 0; arg[n][i] != '\0'; i++) {
            tab_cmd[n][a] = arg[n][i];
            a++;
        }
    } tab_cmd[n] = NULL;
    for (n = 0; arg[n] != NULL; n++)
        free(arg[n]);
    free(arg);
    return tab_cmd;
}
