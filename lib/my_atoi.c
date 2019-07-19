/*
** EPITECH PROJECT, 2019
** my_atoi.c
** File description:
** My version of atoi function.
*/

int my_atoi(char const * const str)
{
    int i = 0;
    int nb = 0;
    int sign = 1;

    for (; (str[i] < '0' || str[i] > '9') &&
        str[i] != '\0'; i++)
        if (str[i] == '-')
            sign *= -1;
    for (; str[i] >= '0' && str[i] <= '9'; i++)
        nb = (10 * nb) + str[i] - '0';
    nb *= sign;
    return (nb);
}
