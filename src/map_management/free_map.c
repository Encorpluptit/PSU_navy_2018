/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Function for freeing map.
*/

#include <stdlib.h>
#include "essentials.h"
#include "map_management.h"

int free_map(char **map)
{
    for (uint8_t i = 0; i < MAP_SIZE; ++i)
        free(*(map + i));
    free(map);
    return SUCCESS;
}
