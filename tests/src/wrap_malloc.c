/*
** EPITECH PROJECT, 2019
** Any project.
** File description:
** Wrapping malloc for unit tests purposes.
*/

#include <errno.h>
#include <fcntl.h>
#include "tests_run.h"
#include "map_management.h"
#include "map_parser.h"

bool malloc_fail(bool set, int val)
{
    static int count = 0;

    if (set)
        count = val;
    else
        count--;
    return count == 0;
}

void *wrap_malloc(size_t s)
{
    if (SHOULD_MALLOC_FAIL()) {
        errno = ENOMEM;
        return NULL;
    }
    return REAL_MALLOC(s);
}

Test(mf_create_map, test_1)
{
    SET_MALLOC_FAIL(1);
    cr_assert_null(create_map());
}

Test(mf_create_map, test_2)
{
    SET_MALLOC_FAIL(3);
    cr_assert_null(create_map());
}

Test(mf_parser_entry, test1)
{
    char **map = NULL;

    SET_MALLOC_FAIL(3);
    map = parser_entry("tests/ressources/easy_map");
    cr_assert_null(map);
    free_map(map);
}

Test(mf_parser_entry, test2)
{
    char **map = NULL;

    SET_MALLOC_FAIL(2);
    map = parser_entry("tests/ressources/easy_map");
    cr_assert_null(map);
    free_map(map);
}

Test(mf_parser_entry, test3)
{
    char **map = NULL;

    SET_MALLOC_FAIL(14);
    map = parser_entry("tests/ressources/easy_map");
    cr_assert_null(map);
    free_map(map);
}

Test(mf_read_map, test1)
{
    char **map = NULL;
    int fd = open("tests/ressources/easy_map", O_RDONLY);

    SET_MALLOC_FAIL(1);
    map = read_map(fd);
    cr_assert_null(map);
    free_map(map);
}
