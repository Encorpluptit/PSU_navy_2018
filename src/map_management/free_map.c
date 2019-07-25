/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Function for freeing map.
*/

#include <stdlib.h>
#include "essentials.h"
#include "map_management.h"
#include "printf.h"

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
    free_map(map);
    free_map(enemy_map);

    if (!return_code)
        my_printf("I won\n");
    else if (return_code == 1)
        my_printf("Enemy won\n");
    else
        my_printf("%e\n", "ERROR");
    return return_code;
}
