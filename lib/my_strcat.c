/*
** EPITECH PROJECT, 2019
** Any Project.
** File description:
** Reproduce strcat function.
*/

#include <stdlib.h>
#include "essentials.h"

static char *my_realloc(char *ptr, size_t size);

int my_strcat(char **line, char **buffer)
{
    char *buff_cpy = *buffer;
    char *free_ptr = *buffer;
    int i = 0;

    if (!(*buffer))
        return ERROR;
    for (; *buff_cpy; buff_cpy++);
    if (*line != NULL)
        for (; (*line)[i]; i++);
    *line = my_realloc(*line, sizeof(char) * (i + (buff_cpy - *buffer) + 1));
    if (*line == NULL)
        return ERROR;
    for (; *buffer != buff_cpy; (*buffer) += 1)
        (*line)[i++] = **buffer;
    (*line)[i] = '\0';
    free(free_ptr);
    return (SUCCESS);
}

static char *my_realloc(char *ptr, size_t size)
{
    char *result = NULL;
    char *tmp = NULL;
    char *ptr_free = ptr;

    if (ptr == NULL)
        return (malloc(size));
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    result = malloc(size);
    if (result == NULL)
        return NULL;
    tmp = result;
    for (; *ptr && size != 0; size -= 1)
        *(tmp++) = *(ptr++);
    free(ptr_free);
    return (result);
}
