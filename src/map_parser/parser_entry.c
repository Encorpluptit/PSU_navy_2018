/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Map_parser point of entry.
*/

#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include "essentials.h"
#include "map_parser.h"

char **parser_entry(char *map_path)
{
    char **map = NULL;
    int fd = open(map_path, O_RDONLY);

    if (fd == FILE_ERROR || (check_map_error(fd) == ERROR)) {
        close(fd);
        return NULL;
    }
    if (!(map = read_map(fd))) {
        close(fd);
        return NULL;
    }
}
