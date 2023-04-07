/*
** EPITECH PROJECT, 2022
** int_single.c
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

int get_size_file(char *file)
{
    struct stat st;
    int fd, size;

    fd = open(file, O_RDONLY);
    if (fd == -1) {
        perror("Erreur : impossible d'ouvrir le fichier");
        return -1;
    }
    if (fstat(fd, &st) == -1) {
        perror("Erreur : impossible de récupérer les informations du fichier");
        close(fd);
        return -1;
    }
    size = st.st_size;
    close(fd);
    return size;
}

int init_int_single(i_s *info_shell)
{
    if (info_shell->st_redi.redir_type[0] != 1)
        return 0;
    if (access(info_shell->st_redi.redir_file_in, F_OK) != 0) {
        double_write(info_shell->st_redi.redir_file_in,
            ": No such file or directory.\n");
        return 84;
    }
    info_shell->st_redi.fd = open(info_shell->st_redi.redir_file_in, O_RDONLY);
    if (info_shell->st_redi.fd == -1) {
        double_write(info_shell->st_redi.redir_file_in,
            ": Permission denied.\n");
        return 84;
    }
    info_shell->st_redi.old = dup(STDIN_FILENO);
    return 0;
}

int child_int_single(i_s *info_shell)
{
    if (info_shell->st_redi.redir_type[0] != 1 ||
        info_shell->st_pipe.pos != info_shell->st_pipe.pos_max)
        return 0;
    if (dup2(info_shell->st_redi.fd, STDIN_FILENO) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
    return 0;
}

void reset_int_single(i_s *info_shell)
{
    if (info_shell->st_redi.redir_type[0] != 1)
        return;
    close(info_shell->st_redi.fd);
    dup2(info_shell->st_redi.old, STDIN_FILENO);
    close(info_shell->st_redi.old);
    return;
}
