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
    if (ac == 2)
        return player_one_entry(av[1]);
    else
        return player_two_entry(av[1], av[2]);
    return SUCCESS;
}
