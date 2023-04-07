##
## EPITECH PROJECT, 2022
## makefile
## File description:
## MINISHELL
##

SRC 	=	src/function/mini_printf.c \
			src/function/my_put_nbr.c \
			src/function/my_putchar.c \
			src/function/my_putstr.c \
			src/function/my_compute_power_rec.c \
			src/function/my_revstr.c \
			src/function/my_str_to_word_array.c \
			src/function/my_getnbr.c \
			src/function/my_strcmp.c \
			src/function/my_strcp.c \
			src/function/my_strupper.c \
			src/function/my_strncmp.c \
			src/cmd_shell/my_cd.c \
			src/cmd_shell/my_env.c \
			src/cmd_shell/my_unsetenv.c \
			src/cmd_shell/my_exit.c \
			src/cmd_shell/my_other/my_other.c \
			src/cmd_shell/my_other/function_my_other.c \
			src/cmd_shell/my_setenv/my_setenv.c \
			src/cmd_shell/my_setenv/edit_env.c \
			src/cmd_shell/my_setenv/new_env.c \
			src/cmd_shell/my_pwd.c \
			src/cmd_shell/my_echo.c \
			src/cmd_shell/my_execute.c \
			src/shell/write_error.c \
			src/shell/verif_signal.c \
			src/shell/all_cleaner.c \
			src/shell/error_shell.c \
			src/shell/get_cmd.c \
			src/shell/start_cmd.c \
			src/shell/shell.c \
			src/shell/function_shell.c \
			src/shell/redirect/redirect_utils.c \
			src/shell/redirect/redirect_add.c \
			src/shell/redirect/redirect_error.c \
			src/shell/redirect/redirect_cleaner.c \
			src/shell/redirect/redirect_pipe.c \
			src/shell/redirect/int_double.c \
			src/shell/redirect/int_single.c \
			src/shell/redirect/redirect.c \
			src/shell/pipe/main_pipe.c \
			src/shell/pipe/start_cmd_pipe.c \
			src/shell/pipe/pipe_error.c \
			src/function.c \
			src/init.c \
			src/free.c \
			src/main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I ./include/ -g

NAME	=	mysh

all:	$(NAME)

$(NAME): $(OBJ)
	@echo -e "🔨 \033[0;32mCompile Mysh \033[0;30m🔨"
	gcc $(OBJ) $(CFLAGS) -o $(NAME) -lncurses
	@echo -e "✅ \033[0;31mMysh compiled ✅ \033[0m"

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug :
	gcc $(SRC) -Wall -Wextra -I include -o $(NAME) -g $(CFLAGS)

.PHONY:	all clean fclean re
