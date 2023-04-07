/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int my_strlen(char const *str);
int my_getnbr(char const *str);
int mini_printf(const char *format, ...);
char *my_strdup(char *str);
char *my_strcpy(char *dest, char const *src);

char *my_strdup(char *str)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));
    int n = 0;
    for (; str[n] != '\0'; n++)
        result[n] = str[n];
    result[n] = '\0';
    return result;
}

int suite_calc_size_tab(char char_t, char char_s)
{
    if (char_t == char_s)
        return 1;
    return 0;
}

int calc_size_tab(char *tab, char *sep)
{
    int nb = 1;
    for (int n = 0; sep[n] != '\0'; n++) {
        for (int a = 0; tab[a] != '\0'; a++)
            nb += suite_calc_size_tab(sep[n], tab[a]);
    }
    return nb;
}

char **my_str_to_word_array(char *tab, char *sep)
{
    char *tmp_2 = my_strdup(tab);
    int size_tab = calc_size_tab(tab, sep);
    char **result = malloc(sizeof(char *) * (size_tab + 2));
    char *tmp = strtok(tmp_2, sep);
    int pos = 1;
    result[0] = my_strdup(tmp);
    while (1) {
        tmp = strtok(NULL, sep);
        if (tmp == NULL)
            break;
        result[pos] = malloc(sizeof(char) * (my_strlen(tmp) + 2));
        result[pos] = my_strcpy(result[pos], tmp);
        pos++;
    }
    result[pos] = NULL;
    return result;
}
