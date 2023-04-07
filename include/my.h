/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** all prototypes and include
*/

#ifndef MY_H_
    #define MY_H_

////////////////////////////////////////////////////////////////////////////////
///////////////////////  LIB  //////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <ncurses.h>
    #include <signal.h>

    #include "struct_all.h"
    #include "my.h"

    // Function:
    int mini_printf(const char *format, ...);
    char **read_file(char *av[]);
    int mini_printf(const char *format, ...);
    int printf_credit(int tmp);
    int my_strlen(char const *str);
    char *my_put_nbr_modif(int nb);
    int	my_getnbr(char const *str);
    int my_power(int nb, int p);
    char **my_double_tab(char *buffer, char separator);
    int my_strcmp(char const *s1, char const *s2);
    char *my_put_nbr_modif(int nb);
    char *my_put_nbr_double(int nb);
    char *my_revstr(char *str);
    char* my_inv_double_tab(char** txt);
    char* my_inv_double_tab_html(char** txt);
    char *my_strcpy(char *dest, char const *src);
    char **my_str_to_word_array(char *tab, char *sep);
    void fill(char *str, int size);
    char pass_char_wait(int hit, int pos);
    char *my_strcpy(char *dest, char const *src);
    char *my_strupper(char *str);
    int my_strncmp(char const *s1, char const *s2, int n);
    int my_strcmp_p(char const *s1, char const *s2);


////////////////////////////////////////////////////////////////////////////////
///////////////////////  SHELL  ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

///////////////////////// SHEL ///
    // Shell:
    int shell(i_s *info_shell);
    char *get_cmd(i_s *info_shell);
    int cherch_periph(i_s *info_shell);
    int start_cmd(i_s *info_shell, char *nb_cmd);
    void error_shell(i_s *info_shell, int nb_error);
    int cherch_nb_dir(char **dir);
    char *my_cleaner(char *cmd);
    int cleaner_and_patch(char *cmd);

    // Function_Shell:
    int nb_arg(char *cmd);
    int cherch_nb_dir(char **dir);
    int cherch_in_env(char *env, char *cmd);
    int verif_signal(int pid);
    int verif_perm_directo(char *directo);
    void print_deb(void);
    void sigint_signal_gesture(int sig);
    int verif_espace(char *str);
    void reset_redirect(i_s *info_shell);
    char *one_word(char *cmd);
    char *err_one_word(char *cmd);

///////////////////////// REDIRECT ///
    // Redirect
    void redirect_out_double(i_s *info_shell);
    int child_int_single(i_s *info_shell);
    char **redirect_int_double(i_s *info_shell, char* cmd);

    // Fonction Redirect:
    char *get_cmd_redi(void);
    char **create_tab_cmd(char *cmd, char **arg);
    int start_redirect(i_s *info_shell, char *cmd);
    void stop_redirect(i_s *info_shell);
    int redirect_error(i_s *info_shell, char *cmd);
    int rep_error(char *cmd);
    void add_redir(i_s *info_shell, char *cmd);
    char *redirect_cleaner_cmd(char *cmd);
    int arg_redirect(i_s *info_shell);
    void reset_in(i_s *info_shell);

    // Redirect In Single:
    int init_int_single(i_s *info_shell);
    int child_int_single(i_s *info_shell);
    void reset_int_single(i_s *info_shell);
    int redirect_out_single(i_s *info_shell);

    // Redirect Double Single:
    int init_int_double(i_s *info_shell);
    int child_int_double(i_s *info_shell);
    void reset_int_double(i_s *info_shell);
    int init_file_double(i_s *info_shell);
    char **get_out_int_double(i_s *info_shell, char* cmd);

///////////////////////// PIPE ///
    // Pipe:
    int main_pipe(i_s *info_shell, char *cmd);
    int start_cmd_pipe(i_s *info_shell, char *cmd);
    int my_other_pipe(i_s *info_shell, char *arg, char *cmd);
    int my_execute_pipe(i_s *info_shell, char *cmd);
    char *redirect_pipe(i_s *info_shell, char *cmd);

    // Utils exc pipe:
    int verif_path_exist(i_s *info_shell);
    char *create_directo(i_s *info_shell, char *access);
    int finish_execute_file(char *cmd, int n_slach);
    int nb_slach(char *cmd);
    char *no_cmd(int size_cmd, char *arg);
    void piped(i_s *info_shell);

    // Error Pipe:
    int pipe_error(i_s *info_shell, char *cmd);

    // TMP:
    void all_close_pipe(i_s *info_shell);
    void waitpid_pipe(i_s *info_shell);
    void signal_pipe(i_s *info_shell, pid_t r_fork);


////////////////////////////////////////////////////////////////////////////////
///////////////////////  COMMAND  //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    // Command:
    int my_cd(i_s *info_shell, char *cmd);
    int my_env(i_s *info_shell, char *cmd);
    int my_exit(i_s *info_shell, char *cmd);
    int my_setenv(i_s *info_shell, char *cmd);
    int my_unsetenv(i_s *info_shell, char *cmd);
    int my_other(i_s *info_shell, char *arg, char *cmd);
    int my_pwd(i_s *info_shell, char *cmd);
    int my_echo(i_s *info_shell, char *cmd);
    int my_execute(i_s *info_shell, char *cmd);

    // Function my_other:
    char *cherch_path(i_s *info_shell);
    char *my_other_edit_arg(char *arg);
    char **cherch_dr(i_s *info_shell, char *cmd);
    char *add_cmd(char *path, char *cmd);

    // Command my_setenv && my_unsetenv:
    int new_env(i_s *info_shell, char *arg);
    int edit_env(i_s *info_shell, char **tab_cmd, int nb_arg, int pos_env);
    int cherch_arg_env(i_s *info_shell, char *cmd);


////////////////////////////////////////////////////////////////////////////////
///////////////////////  OTHER  ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    // Function Write Error:
    int three_write(char *str_1, char *str_2, char *str_3);
    int double_write(char *str_1, char *str_2);
    int write_error(char const *str);
    int error_env(char *str_1, char *str_2, char *str_3);
    int write_error_rep(char const *str);

    // Cleaner:
    char *my_cleaner(char *cmd);
    int dual_rect_error(i_s *info_shell, char *cmd);
    char *cleaner_espace(char *cmd);

    // Init && Free:
    int init_struct(i_s *info_shell, char **env);
    void free_struct(i_s *info_shell);


////////////////////////////////////////////////////////////////////////////////
///////////////////////  COLOR  ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    // Color:
    #define CDEF  "\x1B[0m"

    #define CBLD  "\x1B[1m"
    #define CFNT  "\x1B[2m"
    #define CITA  "\x1B[3m"
    #define CUND  "\x1B[4m"
    #define CINV  "\x1B[7m"
    #define CTGH  "\x1B[9m"
    #define CBLK  "\x1B[30m"
    #define CRED  "\x1B[31m"
    #define CGRN  "\x1B[32m"
    #define CYEL  "\x1B[33m"
    #define CBLU  "\x1B[34m"
    #define CMAG  "\x1B[35m"
    #define CCYN  "\x1B[36m"
    #define CWHT  "\x1B[37m"


#endif /* !MY_H_ */
