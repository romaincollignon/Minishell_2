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

int suite_rep_error(char *cmd, int n)
{
    if (cmd[n] == '>') {
        if (cmd[n + 1] == '<') {
            return write_error_rep("Missing name for redirect.\n");
        } if (my_strlen(cmd) > (n + 2) && cmd[n + 1] == '>' &&
            cmd[n + 2] == '>') {
            return write_error_rep("Missing name for redirect.\n");
        } if (my_strlen(cmd) > (n + 2) && cmd[n + 1] == ' ' &&
            (cmd[n + 2] == '>' || cmd[n + 2] == '<'))
            return write_error_rep("Missing name for redirect.\n");
    } if (cmd[n] == '<') {
        if (cmd[n + 1] == '>') {
            return write_error_rep("Missing name for redirect.\n");
        } if (my_strlen(cmd) > (n + 2) && cmd[n + 1] == '<' &&
            cmd[n + 2] == '<') {
            return write_error_rep("Missing name for redirect.\n");
        } if (my_strlen(cmd) > (n + 2) && cmd[n + 1] == ' ' &&
            (cmd[n + 2] == '>' || cmd[n + 2] == '<'))
            return write_error_rep("Missing name for redirect.\n");
    } return 0;
}

int rep_error(char *cmd)
{
    int nb = 0;
    if (my_strlen(cmd) > 1 && (cmd[0] == '<' || cmd[0] == '>'))
        return write_error_rep("Invalid null command.\n");
    for (int n = 0; cmd[n] != '\0'; n++) {
        if (cmd[n] != ' ' && cmd[n] != '>' && cmd[n] != '<')
            nb++;
    }
    if (cmd[my_strlen(cmd) - 1] == '<' || cmd[my_strlen(cmd) - 1] == '>')
        return write_error_rep("Missing name for redirect.\n");
    if (nb == 0)
        return write_error_rep("Missing name for redirect.\n");
    for (int n = 0; cmd[n] != '\0'; n++) {
        if (suite_rep_error(cmd, n) == 1)
            return 1;
    } return 0;
}

void compt_redir(i_s *info_shell, char *cmd)
{
    for (int n = 0; cmd[n] != '\0'; n++) {
        if (cmd[n] == '<' && cmd[n + 1] != '<') {
            info_shell->st_redi.redir_type[0]++;
        } if (cmd[n] == '<' && cmd[n + 1] == '<') {
            info_shell->st_redi.redir_type[1]++;
            n++;
        } if (cmd[n] == '>' && cmd[n + 1] != '>') {
            info_shell->st_redi.redir_type[2]++;
        } if (cmd[n] == '>' && cmd[n + 1] == '>') {
            info_shell->st_redi.redir_type[3]++;
            n++;
        } if (cmd[n] == '|') {
            info_shell->st_pipe.nb_pipe++;
        }
    }
}

int dual_rect_error(i_s *info_shell, char *cmd)
{
    compt_redir(info_shell, cmd);
    if (info_shell->st_redi.redir_type[0] != 0 &&
        info_shell->st_redi.redir_type[1] != 0)
        return write_error_rep("Ambiguous output redirect.\n");
    if (info_shell->st_redi.redir_type[2] != 0 &&
        info_shell->st_redi.redir_type[3] != 0)
        return write_error_rep("Ambiguous input redirect.\n");
    for (int n = 0; cmd[n + 1] != '\0'; n++) {
        if (cmd[n] == '|' && cmd[n + 1] == '|')
            return write_error_rep("Invalid null command.\n");
    }
    return 0;
}

int redirect_error(i_s *info_shell, char *cmd)
{
    if (rep_error(cmd) == 1)
        return 1;
    if (dual_rect_error(info_shell, cmd) == 1)
        return 1;
    if (pipe_error(info_shell, cmd) == 1)
        return 1;
    add_redir(info_shell, cmd);
    for (int n = 0; cmd[n] != '\0'; n++)
        if (cmd[n] == '<' || cmd[n] == '>' || cmd[n] == '|')
            return 2;
    return 0;
}
