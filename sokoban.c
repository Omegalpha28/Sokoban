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

void display(char **world, size_tab *s, element *e, char **backup_world)
{
    int t_pressed;

    s->goal = search_goal(world, s);
    s->playing = search_goal(world, s);
    search_player(world, e);
    world[e->pos_x][e->pos_y] = ' ';
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    while (s->playing != 0) {
        my_display_in_center(stdscr, world, s, e);
        t_pressed = getch();
        compare_world(backup_world, world, s);
        moving_player(e, world, backup_world, t_pressed);
        if (end_game(world, s) == 1)
            s->playing = 0;
    }
    my_display_in_center(stdscr, world, s, e);
    endwin();
}

int create_tab(char const *word, element *e)
{
    size_tab s;
    char **world;
    char **backup_world;

    s.stuck = 0;
    s.size_col = my_column(word);
    s.size_length = my_length(word);
    if (verif_word(word) == 84) {
        return 84;
    }
    world = malloc(sizeof(char *) * (s.size_col + 1));
    world = my_convert_tab(word, world, s.size_col, s.size_length);
    backup_world = malloc(sizeof(char *) * (s.size_col + 1));
    backup_world = my_convert_tab_void(word, backup_world, s.size_col,
        s.size_length);
    display(world, &s, e, backup_world);
    my_display_world(world, &s, e);
    free(world);
    return s.stuck;
}

int sokoban(char **av, int fd, element *e)
{
    int size_word = 0;
    struct stat c;
    char *word = NULL;
    int retour = 0;

    stat(av[1], &c);
    word = malloc(c.st_size + 1);
    if (word != NULL) {
        read(fd, word, c.st_size);
        word[c.st_size] = '\0';
        retour = create_tab(word, e);
        free(word);
        return retour;
    } else {
        write(2, "Empty File\n", 12);
        free(word);
        return 84;
    }
}

int main(int ac, char **av)
{
    element e;

    e.box = "X";
    e.goal = "O";
    e.player = "P";
    e.wall = "#";
    if (ac == 2) {
        return (is_help(av, &e));
    } else {
        write(2, "Nope!\n", 7);
        return 84;
    }
}
