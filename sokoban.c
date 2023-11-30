/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** it's my main bro
*/
#include <curses.h>
#include <stdio.h>
#include "sokoban.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int display(char const *word)
{
    initscr();
    printf("%s", word);
    mvwaddstr(stdscr, 0, 0, word);
    refresh();
    getch();
    endwin();
}

int sokoban(char **av, int fd)
{
    int reading = 0;
    struct stat c;
    char *word = NULL;
    char **world;

    stat(av[1], &c);
    word = malloc(c.st_size + 1);
    if (word != NULL) {
        reading = read(fd, word, c.st_size);
        word[c.st_size] = '\0';
        printf("%s", word);
        display(word);
    } else {
        write(2, "Empty File\n", 12);
        return 84;
    }
    return 0;
}

void my_help(void)
{
    my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n     map  file ");
    my_putstr("representing the warehouse map, containing ‘#’ for walls,\n");
    my_putstr("          ");
    my_putstr("‘P’ for the player, ‘X’ for boxes and ‘O’ for storage ");
    my_putstr("locations.\n");
}

int is_help(char **av)
{
    int fd = 0;

    if (my_strcmp(av[1], "-h") == 0) {
        my_help();
        return 0;
    }
    fd = open(av[1], O_RDONLY);
    if (fd != -1) {
        return (sokoban(av, fd));
    } else {
        write(2, "Nope!\n", 7);
        return 84;
    }
}

int main(int ac, char **av)
{
    if (ac == 2) {
        return (is_help(av));
    } else {
        write(2, "Nope!\n", 7);
        return 84;
    }
}
