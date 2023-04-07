/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** task06
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int result = 0;
    for (int n = 0; s1[n] != '\0'; n = n + 1) {
        if (s1[n] < s2[n]) {
            result = s1[n] - s2[n];
            return result;
        }
        if (s1[n] > s2[n]) {
            result = s1[n] - s2[n];
            return result;
        }
    }
    return 0;
}

int my_strcmp_p(char const *s1, char const *s2)
{
    int result = 0;
    if (my_strlen(s1) != my_strlen(s2))
        return 82;
    for (int n = 0; s1[n] != '\0'; n = n + 1) {
        if (s1[n] < s2[n]) {
            result = s1[n] - s2[n];
            return result;
        }
        if (s1[n] > s2[n]) {
            result = s1[n] - s2[n];
            return result;
        }
    }
    return 0;
}
