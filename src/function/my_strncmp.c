/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** task07
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int result = 0;
    for (int a = 0; a < n; a = a + 1) {
        if (s1[a] < s2[a]) {
            result = s1[a] - s2[a];
            return result;
        }
        if (s1[a] > s2[a]) {
            result = s1[a] - s2[a];
            return result;
        }
    }
    return 0;
}
