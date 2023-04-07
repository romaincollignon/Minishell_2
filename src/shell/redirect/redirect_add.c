/*
** EPITECH PROJECT, 2022
** redirect_error.c
** File description:
** Function : redirect_error
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

#include "../../../include/struct_all.h"
#include "my.h"

void start_cp_in(i_s *info_shell, char *cmd, int n)
{
    n++;
    int i = 0;
    for (; cmd[n] != '\0' && cmd[n] != ' ' && cmd[n] != '<' && cmd[n] != '>'
        && cmd[n] != '|'; n++) {
        info_shell->st_redi.redir_file_in[i] = cmd[n];
        i++;
    } info_shell->st_redi.redir_file_in[i] = '\0';
}

void start_cp_out(i_s *info_shell, char *cmd, int n)
{
    int i = 0;
    n++;
    for (; cmd[n] != '\0' && cmd[n] != ' ' && cmd[n] != '<' && cmd[n] != '>'
        && cmd[n] != '|'; n++) {
        info_shell->st_redi.redir_file_out[i] = cmd[n];
        i++;
    } info_shell->st_redi.redir_file_out[i] = '\0';
}

void alloc_redir(i_s *info_shell, char *cmd)
{
    free(info_shell->st_redi.redir_file_in);
    info_shell->st_redi.redir_file_in =
        malloc(sizeof(char) * (my_strlen(cmd) + 5));
    free(info_shell->st_redi.redir_file_out);
    info_shell->st_redi.redir_file_out =
        malloc(sizeof(char) * (my_strlen(cmd) + 5));
    info_shell->st_redi.redir_file_in[0] = '#';
    info_shell->st_redi.redir_file_in[1] = '8';
    info_shell->st_redi.redir_file_in[2] = '#';
    info_shell->st_redi.redir_file_in[3] = '\0';
    info_shell->st_redi.redir_file_out[0] = '#';
    info_shell->st_redi.redir_file_out[1] = '8';
    info_shell->st_redi.redir_file_out[2] = '#';
    info_shell->st_redi.redir_file_out[3] = '\0';
}

void add_redir(i_s *info_shell, char *cmd)
{
    alloc_redir(info_shell, cmd);
    int tmp = 0;
    for (int n = 0; cmd[n] != '\0'; n++) {
        if (cmd[n] == '<' && cmd[n + 1] == '<') {
            start_cp_in(info_shell, cmd, n + 2);
            n = n + 2;
            tmp++;
        } if (cmd[n] == '>' && cmd[n + 1] == '>') {
            start_cp_out(info_shell, cmd, n + 2);
            n = n + 2;
            tmp++;
        } if (cmd[n] == '<') {
            start_cp_in(info_shell, cmd, n + 1);
            n++;
        } if (cmd[n] == '>') {
            start_cp_out(info_shell, cmd, n + 1);
            n++;
            tmp++;
        }
    }
}
