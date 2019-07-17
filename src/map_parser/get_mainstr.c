/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Open the file, getting size with stat, malloc accordindgly, return str
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "map_parser.h"

static char *read_fct(int fd, int size);
static int stat_fct(int fd);

char *get_mainstr(char const *map_path)
{
    char *main_str = NULL;
    int fd = open(map_path, O_RDONLY);
    int size = -1;

    if (fd == FILE_ERROR || ((size = stat_fct(fd)) == FILE_ERROR))
        return (NULL);
    if (!(main_str = read_fct(fd, size)))
        return NULL;
    close(fd);
    return (main_str);
}

static int stat_fct(int fd)
{
    int file_size = 0;
    int read_rt = 0;
    char *tmp = malloc(sizeof(char) * 2);

    if (!tmp)
        return FILE_ERROR;
    while ((read_rt = read(fd, tmp, 1)) > 0)
        file_size += 1;
    if (read_rt == FILE_ERROR)
        file_size = FILE_ERROR;
    free(tmp);
    return (file_size);
}

static char *read_fct(int fd, int size)
{
    char *buffer = malloc(sizeof(char) * (size + 1));

    if (buffer == NULL)
        return (NULL);
    lseek(fd, 0, SEEK_SET);
    if (read(fd, buffer, size) >= 0)
        buffer[size] = '\0';
    else {
        free(buffer);
        return NULL;
    }
    return (buffer);
}
