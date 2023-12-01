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
#include "sokoban.h"

void display(char **world, int size_col)
{
    initscr();
    my_display_in_center(stdscr, world, size_col);
    refresh();
    getch();
    endwin();
}

int create_tab(char const *word)
{
    char **world;
    int size_col = my_column(word);
    int size_length = my_length(word);

    world = malloc(sizeof(char *) * (size_col + 1));
    world = my_convert_tab(word, world, size_col, size_length);
    display(world, size_col);
}

int sokoban(char **av, int fd)
{
    int size_word = 0;
    struct stat c;
    char *word = NULL;

    stat(av[1], &c);
    word = malloc(c.st_size + 1);
    if (word != NULL) {
        read(fd, word, c.st_size);
        word[c.st_size] = '\0';
        create_tab(word);
        free(word);
        return 0;
    } else {
        write(2, "Empty File\n", 12);
        free(word);
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
