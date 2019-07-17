/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Main for navy project, error gestion and lauching navy.
*/

#include "essentials.h"
#include "navy.h"

int main(int ac, char **av, char **env)
{
    if (ac < 2 || ac > 4 || !env)
        return 84;
    char **test = parser_entry(av[1]);
    return SUCCESS;
}
