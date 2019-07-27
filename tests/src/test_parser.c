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

Test(parser_entry_bad_map, test8)
{
    char **map = parser_entry("tests/ressources/wrong_syntax8");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test9)
{
    char **map = parser_entry("tests/ressources/wrong_syntax9");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test10)
{
    char **map = parser_entry("tests/ressources/wrong_syntax10");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test11)
{
    char **map = parser_entry("tests/ressources/wrong_syntax11");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test12)
{
    char **map = parser_entry("tests/ressources/wrong_syntax12");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test13)
{
    char **map = parser_entry("tests/ressources/wrong_syntax13");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test14)
{
    char **map = parser_entry("tests/ressources/wrong_syntax14");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test15)
{
    char **map = parser_entry("tests/ressources/wrong_syntax15");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test16)
{
    char **map = parser_entry("tests/ressources/wrong_syntax16");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test17)
{
    char **map = parser_entry("tests/ressources/wrong_syntax17");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test18)
{
    char **map = parser_entry("tests/ressources/wrong_syntax18");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test19)
{
    char **map = parser_entry("tests/ressources/wrong_syntax19");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test20)
{
    char **map = parser_entry("tests/ressources/wrong_syntax20");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_bad_map, test21)
{
    char **map = parser_entry("tests/ressources/wrong_syntax21");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_superposition, test1)
{
    char **map = parser_entry("tests/ressources/superpostion");

    cr_assert_null(map);
    free_map(map);
}

Test(parser_entry_superposition, test2)
{
    char **map = parser_entry("tests/ressources/superpostion2");

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

/* Test(fill_line_error_in_create_map, test1) */
/* { */
/*     char **map = create_map(); */

/*     map[0][2] = 'p'; */
/*     map = fill_map(map, "2:C1:C2"); */
/*     cr_assert_null(map, "%s", map[0]); */
/*     free_map(map); */
/* } */
