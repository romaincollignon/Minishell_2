/*
** EPITECH PROJECT, 2022
** my_strcp.c
** File description:
** task01
*/

void my_putchar(char c);
int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int n = 0;
    int taille = my_strlen(src);
    while (n <= taille) {
        dest[n] = src[n];
        n = n + 1;
    }
    dest[n] = '\0';
    return dest;
}
