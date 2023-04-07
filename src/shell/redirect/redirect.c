/*
** EPITECH PROJECT, 2022
** redirect.c
** File description:
** Function : start_redirect, close_redirect
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

#include "../../../include/struct_all.h"
#include "my.h"

void dupli_tab_redi(i_s *info_shell, char *cmd)
{
    int size = 0;
    while (info_shell->st_redi.file_tmp[size] != NULL)
        size++;
    char *new_str = (char*)malloc((my_strlen(cmd) + 1) * sizeof(char));
    if (new_str == NULL) return;
    my_strcpy(new_str, cmd);
    char **new_tab = (char**)malloc((size + 2) * sizeof(char*));
    if (new_tab == NULL) {
        free(new_str);
        return;
    } if (size == 0 && info_shell->st_redi.file_tmp[0] == NULL) {
        new_tab[0] = new_str;
        new_tab[1] = NULL;
    } else {
        for (int i = 0; i < size; i++) {
            new_tab[i] = info_shell->st_redi.file_tmp[i];
        } new_tab[size] = new_str;
        new_tab[size + 1] = NULL;
    } free(info_shell->st_redi.file_tmp);
    info_shell->st_redi.file_tmp = new_tab;
}

void init_file_tmp(i_s *info_shell)
{
    info_shell->st_redi.file_tmp = malloc(sizeof(char *) * 3);
    info_shell->st_redi.file_tmp[0] = malloc(sizeof(char) * 3);
    info_shell->st_redi.file_tmp[0][0] = '~';
    info_shell->st_redi.file_tmp[0][1] = '\0';
    info_shell->st_redi.file_tmp[0] = NULL;
}

int arg_redirect(i_s *info_shell)
{
    int error = 0;
    char *tmp_char;
    int i = 0;
    init_file_tmp(info_shell);
    while (error == 0) {
        if (info_shell->restart == 1)
            return 0;
        mini_printf("? ");
        tmp_char = get_cmd_redi();
        if (tmp_char[0] == '~' && tmp_char[1] == '\0')
            return 0;
        dupli_tab_redi(info_shell, tmp_char);
        if (my_strcmp_p(info_shell->st_redi.file_tmp[i],
            info_shell->st_redi.redir_file_in) == 0) {
            info_shell->st_redi.file_tmp[i] = NULL;
            return 1;
        }
        i++;
    }
    return 1;
}

int start_redirect(i_s *info_shell, char *cmd)
{
    cmd = redirect_cleaner_cmd(cmd);
    if (info_shell->st_redi.redir_type[0] == 1) {
        if (init_int_single(info_shell) == 84) {
            info_shell->st_redi.err_redir = 84;
            return 84;
        }
    } if (info_shell->st_redi.redir_type[1] == 1) {
        if (init_int_double(info_shell) == 84) {
            info_shell->st_redi.err_redir = 84;
            return 84;
        }
    } if (info_shell->st_redi.redir_type[2] == 1) {
        if (redirect_out_single(info_shell) == 84) {
            info_shell->st_redi.err_redir = 84;
            return 84;
        }
    } if (info_shell->st_redi.redir_type[3] == 1)
        redirect_out_double(info_shell);
    return 0;
}

void stop_redirect(i_s *info_shell)
{
    if (info_shell->st_redi.redir_type[2] != 0 ||
        info_shell->st_redi.redir_type[3] != 0) {
        if (dup2(info_shell->st_redi.old, STDOUT_FILENO) == -1) {
            perror(info_shell->st_redi.redir_file_out);
        }
        close(info_shell->st_redi.old);
    }
    return;
}
