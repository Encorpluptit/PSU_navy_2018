/*
** EPITECH PROJECT, 2019
** my_str_isnum.c
** File description:
** Write a function that return 1 if the sring passed as parameter
** only contains digits and 0 otherwise.
*/

#include "essentials.h"

int my_str_isnum(char const *str)
{
    if (!str || str[0] == '\0')
        return (ERROR);
    for (; *str; ++str) {
        if (*str < '0' || *str > '9')
            return (ERROR);
    }
    return (SUCCESS);
}
