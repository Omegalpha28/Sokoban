/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** it's my main bro
*/
#include <curses.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "sokoban.h"

void display(char **world, size_tab *s, element *e)
{
    int playing = search_goal(world, s);
    int t_pressed;

    search_player(world, e);
    world[e->pos_x][e->pos_y] = ' ';
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    while (getch() != 27 && playing != 0) {
        t_pressed = getch();
        my_display_in_center(stdscr, world, s, e);
        playing += moving_player(e, world, playing, t_pressed);
    }
    endwin();
}

int create_tab(char const *word)
{
    element e;
    size_tab s;
    char **world;

    s.size_col = my_column(word);
    s.size_length = my_length(word);
    e.box = "X";
    e.goal = "O";
    e.player = "P";
    e.wall = "#";
    if (verif_word(word) == 84) {
        write(2, "Bad caracters in file!\n", 24);
        return 84;
    }
    world = malloc(sizeof(char *) * (s.size_col + 1));
    world = my_convert_tab(word, world, s.size_col, s.size_length);
    display(world, &s, &e);
    free(world);
    return 0;
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
