/*
** EPITECH PROJECT, 2022
** all_cleaner.c
** File description:
** Function : all_cleaner
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../../include/struct_all.h"
#include "../../include/my.h"

void deb_cleaner(char *cmd)
{
    for (int n = 0; cmd[n] != '\0'; n++) {
        if (cmd[n] == '\t')
            cmd[n] = ' ';
        if (cmd[n] == '\n')
            cmd[n] = '\0';
    }
    while (cmd[0] == ' ') {
        for (int n = 0; cmd[n] != '\0'; n++)
            cmd[n] = cmd[n + 1];
    }
    if (cmd[0] == '\0')
        return;
    while (cmd[(my_strlen(cmd) - 1)] != '\0' &&
        cmd[(my_strlen(cmd) - 1)] == ' ') {
        cmd[(my_strlen(cmd) - 1)] = '\0';
    }
}

char *my_cleaner(char *cmd)
{

    deb_cleaner(cmd);
    int i = 0;
    int j = 0;
    int len = my_strlen(cmd);
    char *temp = malloc(sizeof(char) * (len + 2));
    if (cmd[0] == '\0') {
        free(temp);
        return cmd;
    }
    for (i = 0; i < len; i++) {
        if (cmd[i] != ' ' || (cmd[i] == ' ' && cmd[i + 1] != ' ')) {
        temp[j++] = cmd[i];
        }
    } temp[j] = '\0';
    free(cmd);
    cmd = malloc(sizeof(char) * (my_strlen(temp) + 2));
    my_strcpy(cmd, temp);
    free(temp);
    return cmd;
}

char *my_cleaner_tab(char *cmd)
{
    for (int n = 0; cmd[n] != '\0'; n++) {
        if (cmd[n] == '\t')
            cmd[n] = ' ';
        if (cmd[n] == '\n')
            cmd[n] = '\0';
    }
    while (cmd[0] == ' ') {
        for (int n = 0; cmd[n] != '\0'; n++)
            cmd[n] = cmd[n + 1];
    }
    if (cmd[0] == '\0')
        return cmd;
    while (cmd[(my_strlen(cmd) - 1)] != '\0' &&
        cmd[(my_strlen(cmd) - 1)] == ' ') {
        cmd[(my_strlen(cmd) - 1)] = '\0';
    }
    return cmd;
}

void suite_cleaner_and_patch(char *cmd, int i, int len, int j)
{
    for (j = i + 1; j < len; j++) {
        cmd[j - 1] = cmd[j];
    }
}

int cleaner_and_patch(char *cmd)
{
    int i, j, k;
    j = 0;
    int len = my_strlen(cmd);
    for (i = 0; i < len - 1; i++) {
        if (cmd[i] == ';' && cmd[i + 1] == ';') {
            suite_cleaner_and_patch(cmd, i, len, j);
            len--;
            i--;
        }
    } while (cmd[0] == ';') {
        for (k = 1; k < len; k++) {
            cmd[k - 1] = cmd[k];
        } len--;
    } while (cmd[len - 1] == ';') {
        len--;
    } cmd[len] = '\0';
    for (int n = 0; cmd[n] != '\0'; n++) {
        if (cmd[n] != ';' && cmd[n] != '\n')
            return 0;
    } return 1;
}
