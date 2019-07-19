/*
** EPITECH PROJECT, 2019
** Library.
** File description:
** Function that return lenght of a string.
*/

#include <stddef.h>

size_t my_strlen(char const *str)
{
    size_t i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}
