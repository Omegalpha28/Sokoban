/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** these function will display the argument given in the center of the map.
*/
#include <curses.h>
#include <unistd.h>
#include "sokoban.h"

void my_display_in_center(WINDOW *stdscr, char **word, int size_col)
{
    int half_width = stdscr->_maxx / 2;
    int half_length = stdscr->_maxy / 2;

    for (int i = 0; i < size_col; i++) {
        wprintw(stdscr, word[i]);
        wprintw(stdscr, "\n");
    }
}
