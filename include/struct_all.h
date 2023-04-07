/*
** EPITECH PROJECT, 2022
** struct_menu.h
** File description:
** struct for all game
*/

#ifndef STRUCT_MENU_H
    #define STRUCT_MENU_H

    typedef struct st_pipe {
        char **tab_pipe;
        int nb_pipe;
        int **pi;
        int pos;
        int pos_max;
        int old;
        int old_out;
        int *waitpid;
    } s_p;

    typedef struct st_redi {
        int *redir_type;
        char *redir_file_in;
        char *redir_file_out;
        int err_redir;
        int fd;
        int old;
        char **file_tmp;
        int restart;
        int *pipe_out;
    } s_r;

    typedef struct info_shell {
        char **env;
        int size_env;
        char *tmp_env;
        int tmp_pos_env;
        char *dir;
        char *back_dir;
        int stop;
        int restart;

        s_r st_redi;
        s_p st_pipe;
    } i_s;

#endif /* !STRUCT_MENU_H */
