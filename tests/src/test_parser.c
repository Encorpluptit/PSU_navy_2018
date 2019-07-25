/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Unit test source file for testing parser.
*/

#include "tests_run.h"
#include "navy.h"
#include "map_parser.h"

Test(parser_entry_wrong_path, test1)
{
    char **map = parser_entry("lol");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test1)
{
    char **map = parser_entry("tests/ressources/wrong_syntax");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test2)
{
    char **map = parser_entry("tests/ressources/wrong_syntax2");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test3)
{
    char **map = parser_entry("tests/ressources/wrong_syntax3");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test4)
{
    char **map = parser_entry("tests/ressources/wrong_syntax4");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test5)
{
    char **map = parser_entry("tests/ressources/wrong_syntax5");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test6)
{
    char **map = parser_entry("tests/ressources/wrong_syntax6");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test7)
{
    char **map = parser_entry("tests/ressources/wrong_syntax7");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_superposition, test1)
{
    char **map = parser_entry("tests/ressources/superpostion");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_easy_map, test1)
{
    char **map = parser_entry("tests/ressources/easy_map");

    cr_assert_not_null(map);
    free_map(map);
}

Test(free_board, test_1, .init = redirect_all_std)
{
    char **map = parser_entry("tests/ressources/easy_map");
    char **enemy_map = parser_entry("tests/ressources/easy_map");

    free_board(map, enemy_map, 0);
}

Test(free_board, test_2, .init = redirect_all_std)
{
    char **map = parser_entry("tests/ressources/easy_map");
    char **enemy_map = parser_entry("tests/ressources/easy_map");

    free_board(map, enemy_map, 1);
}

Test(free_board, test_3, .init = redirect_all_std)
{
    char **map = parser_entry("tests/ressources/easy_map");
    char **enemy_map = parser_entry("tests/ressources/easy_map");

    free_board(map, enemy_map, 2);
}

Test(free_board, test_4, .init = redirect_all_std)
{
    char **map = parser_entry("tests/ressources/easy_map");
    char **enemy_map = parser_entry("tests/ressources/easy_map");

    free_board(map, enemy_map, 3);
}

Test(free_board, test_5, .init = redirect_all_std)
{
    char **map = parser_entry("tests/ressources/easy_map");
    char **enemy_map = parser_entry("tests/ressources/easy_map");

    free_board(map, enemy_map, 84);
}
