/*
** EPITECH PROJECT, 2022
** function_shell.c
** File description:
** Function : print_deb, sigint_signal_gesture, verif_espace, reset_redirect
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

#include "../../include/struct_all.h"
#include "my.h"

void print_deb(void)
{
    if (isatty(0) == 1) {
        mini_printf(CBLD CCYN"• ");
        mini_printf(CRED"My_Shell "CDEF);
        mini_printf(CCYN CBLD"➜ "CDEF);
    }
}

void sigint_signal_gesture(int sig)
{
    if (sig == SIGINT) {
        mini_printf("\n");
        print_deb();
    }
}

int verif_espace(char *str)
{
    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n] != '\t' && str[n] != ' ' && str[n] != '\n')
            return 0;
    }
    return 1;
}

void reset_redirect(i_s *info_shell)
{
    info_shell->st_redi.redir_type[0] = 0;
    info_shell->st_redi.redir_type[1] = 0;
    info_shell->st_redi.redir_type[2] = 0;
    info_shell->st_redi.redir_type[3] = 0;
}

char *err_one_word(char *cmd)
{
    int tmp = 0;
    while (cmd[tmp] != ' ' && cmd[tmp] != '\0' && cmd != NULL)
        tmp++;
    char *result = malloc(sizeof(char) * (tmp + 2));
    for (int n = 0; n <= tmp; n++)
        result[n] = cmd[n];
    result[tmp] = '\0';
    return result;
}
