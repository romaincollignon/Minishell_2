/*
** EPITECH PROJECT, 2022
** my_cd.c
** File description:
** Function : cd
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../../include/struct_all.h"
#include "../../include/my.h"

int go_home(i_s *info_shell)
{
    if (chdir("/home/") == -1)
        write_error("cd: Error Home\n");
    getcwd(info_shell->dir, 256);
    return 0;
}

int verif_arg_cd(char *arg)
{
    if (my_strlen(arg) >= 3 && arg[3] == '-' && arg[4] == '\0')
        return -1;
    int nb = 0;
    for (int n = 0; arg[n] != '\0'; arg++) {
        if (arg[n] == ' ')
            nb++;
    }
    return nb;
}

int change_dir(i_s *info_shell, char *arg)
{
    getcwd(info_shell->back_dir, 256);
    if (chdir(arg) == -1) {
        double_write(arg, ": No such file or directory.\n");
        return 0;
    }
    getcwd(info_shell->dir, 256);
    return 0;
}

static char *good_arg(i_s *info_shell, char *arg)
{
    int dep = 0;
    for (; arg[dep] != ' ' && arg[dep] != '\0'; dep++);
    int size = 0;
    for (int n = dep; arg[n]; n++)
        size++;
    char *result = malloc(sizeof(char) * (size + 2));
    dep++;
    int a = 0;
    for (; arg[dep] != '\0'; dep++) {
        result[a] = arg[dep];
        if (result[a] == '\n') {
            result[a] = '\0';
            break;
        }
        a++;
    } result[a] = '\0';
    free(arg);
    my_strcpy(info_shell->back_dir, result);
    return result;
}

int my_cd(i_s *info_shell, char *cmd)
{
    int error = verif_arg_cd(cmd);
    if (error != -1 && error != 0 && error != 1) {
        return write_error("cd: Too many arguments\n");
    } if (error == 0) {
        go_home(info_shell);
    } if (error == 1) {
        char *go_directo = good_arg(info_shell, cmd);
        int error_perm = verif_perm_directo(go_directo);
        if (error_perm == 1)
            return 0;
        change_dir(info_shell, go_directo);
    } if (error == -1) {
        if (info_shell->back_dir[0] == 'n' && info_shell->back_dir[1] == 'o' &&
        info_shell->back_dir[2] == '\0'){
            return write_error(": No such file or directory.\n");
        } if (chdir(info_shell->back_dir) == -1) {
            write_error("Error command: \'cd -\'\n");
            return 81;
        } getcwd(info_shell->back_dir, 256);
    } return 0;
}
