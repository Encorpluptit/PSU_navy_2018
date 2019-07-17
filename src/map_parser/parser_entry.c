/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Map_parser point of entry.
*/

#include <stddef.h>
#include "printf.h"
#include "map_parser.h"

char **parser_entry(char *map_path)
{
    char **map = NULL;
    char *main_str = get_mainstr(map_path);

    my_printf("%s\n", main_str ? main_str : "NULLstr");
}
