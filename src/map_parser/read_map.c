/*
** EPITECH PROJECT, 2019
** NAvy.
** File description:
** Transform file with boat position into double tab with graphic representation.
*/

#include <stdlib.h>
#include <unistd.h>
#include "essentials.h"
#include "map_management.h"
#include "map_parser.h"

char **fill_map(char **map, char *line);
static char **fill_line(char **map, char *line);
static char **fill_column(char **map, char *line);

char **read_map(int fd)
{
    char **map = create_map();
    char *line;

    if (!map)
        return NULL;
    lseek(fd, 0u, SEEK_SET);
    while ((line = get_next_line(fd))) {
        map = fill_map(map, line);
        free(line);
        if (!map)
            return NULL;
    }
    return map;
}

char **fill_map(char **map, char *line)
{
    if (line[2] == line[5]) {
        if (!(map = fill_line(map, line)))
            return NULL;
    }
    if (line[3] == line[6]) {
        if (!(map = fill_column(map, line)))
            return NULL;
    }
    return map;
}

static char **fill_line(char **map, char *line)
{
    for (uint8_t i = NB_TO_INDEX(line[3]); i <= NB_TO_INDEX(line[6]); ++i) {
        if (map[i][CHAR_TO_INDEX(line[2])] != '.') {
            free_map(map);
            return NULL;
        }
        map[i][CHAR_TO_INDEX(line[2])] = line[0];
    }
    return map;
}

static char **fill_column(char **map, char *line)
{
    for (uint8_t i = CHAR_TO_INDEX(line[2]); i <= CHAR_TO_INDEX(line[5]); ++i) {
        if (map[NB_TO_INDEX(line[3])][i] != '.') {
            free_map(map);
            return NULL;
        }
        map[NB_TO_INDEX(line[3])][i] = line[0];
    }
    return map;
}
