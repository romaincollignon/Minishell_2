/*
** EPITECH PROJECT, 2022
** verif_signal.c
** File description:
** Function : verif_signal
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#include "../../include/struct_all.h"
#include "../../include/my.h"

int verif_signal(int pid)
{
    if (pid == -1 || pid == NULL)
        return 0;
    int status;
    if (waitpid(pid, &status, 0) == -1)
        return 0;
    if (WIFSIGNALED(status) == true) {
        write_error(strsignal(WTERMSIG(status)));
        if (WCOREDUMP(status) == true)
            write_error(" (core dumped)");
        write_error("\n");
    } if (SIGFPE == status) {
        write_error("Floating exception\n");
        if (WCOREDUMP(status) == true)
            write_error(" (core dumped)");
        write_error("\n");
    } if (SIGABRT == status) {
        write_error("Abort (core dumped)\n");
    } if (WIFSTOPPED(status) == true) {
        write_error(strsignal(WSTOPSIG(status)));
    } return 0;
}
