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
    if (!map)
        return SUCCESS;
    for (uint8_t i = 0; i < MAP_SIZE; ++i)
        free(*(map + i));
    free(map);
    return SUCCESS;
}

int free_board(char **map, char **enemy_map, int return_code)
{
    free(map);
    free(enemy_map);
    return return_code;
}
