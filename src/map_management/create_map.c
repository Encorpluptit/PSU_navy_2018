/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Function for getting a blank_map.
*/

#include <stdlib.h>
#include "map_management.h"

int free_map(char **map);

char **create_map(void)
{
    char **map = malloc(sizeof(char *) * (MAP_SIZE + 1));

    if (!map)
        return NULL;
    for (uint8_t i = 0; i < MAP_SIZE; ++i) {
        *(map + i) = malloc(sizeof(char) * (MAP_SIZE + 1));
        if (!(*(map + i))) {
            free_map(map);
            return NULL;
        } else
            FILL_BLANK_LINE;
    }
    *(map + MAP_SIZE) = NULL;
    return map;
}
