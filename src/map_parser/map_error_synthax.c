/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Check map error synthax.
*/

#include <stdlib.h>
#include "essentials.h"
#include "map_parser.h"

static int check_line(char *str, uint8_t index);
static int check_boats(char *line);

int check_map_error(int fd)
{
    char *line = NULL;

    for (uint8_t i = 2; i <= 5; ++i) {
        if (!(line = get_next_line(fd)))
            return ERROR;
        else if ((my_strlen(line) != 7) || check_line(line, i) == ERROR) {
            free(line);
            return ERROR;
        } else
            free(line);
    }
    if ((line = get_next_line(fd))) {
        free(line);
        return ERROR;
    } else
        return SUCCESS;
}

static int check_line(char *line, uint8_t index)
{
    if (!(BOAT_NB(line[0], index)))
        return ERROR;
    if ((line[1] != ':') || (line[4] != ':'))
        return ERROR;
    if (!(UPPERCASE(line[2])) || !(UPPERCASE(line[5])))
        return ERROR;
    if (!(CASE_NB(line[3])) || !(CASE_NB(line[6])))
        return ERROR;
    return (check_boats(line));
}

static int check_boats(char *line)
{
    if (line[2] == line[5]) {
        if (ABS(line[6] - line[3]) + 1 != line[0] - '0')
            return ERROR;
    }
    if (line[3] == line[6]) {
        if (ABS(line[5] - line[2]) + 1 != line[0] - '0')
            return ERROR;
    }
    return SUCCESS;
}
