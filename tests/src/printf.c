/*
** EPITECH PROJECT, 2019
** Any Project.
** File description:
** Testing for printf.h header.
*/

#include "tests_run.h"
#include "printf.h"

Test(my_printf, putchar, .init = redirect_all_std)
{
    my_printf("%c", '\n');
}

Test(my_printf, putpercent, .init = redirect_all_std)
{
    my_printf("%%");
}

Test(my_printf, word_tab, .init = redirect_all_std)
{
    char *tab[3] = {"a", "b", NULL};

    my_printf("%w", tab);
}

Test(my_printf, print_int, .init = redirect_all_std)
{
    int print = 42;

    my_printf("%d", print);
}

Test(my_printf, print_neg_int, .init = redirect_all_std)
{
    int print = -42;

    my_printf("%d", print);
}

Test(my_printf, print_uint, .init = redirect_all_std)
{
    unsigned int print = 42;

    my_printf("%u", print);
}

Test(my_printf, print_iint, .init = redirect_all_std)
{
    short print = 42;

    my_printf("%i", print);
}

Test(my_printf, print_error, .init = redirect_all_std)
{
    char *print = "test";

    my_printf("%e", print);
}

Test(my_printf, print_str, .init = redirect_all_std)
{
    char *print = "test";

    my_printf("%s", print);
}
