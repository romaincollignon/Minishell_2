/*
** EPITECH PROJECT, 2022
** my_strupper.c
** File description:
** task01
*/
void my_putchar(char c);

int my_strlen(char const *str);

char *my_strupper(char *str)
{
    int i = 0;
    while (str[i]) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
        i++;
    }
    return str;
}
