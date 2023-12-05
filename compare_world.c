/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** these function will display the argument given in the center of the map.
*/
#include <curses.h>
#include <unistd.h>
#include "sokoban.h"
#include <stdio.h>

void verif_comparaison(char **back_world, char **world, int i, int j)
{
    if (back_world[i][j] == 'O' && world[i][j] != 'X')
        world[i][j] = 'O';
}

void compare_world(char **back_world, char **world, size_tab *s)
{
    for (int i = 0; i < s->size_col; i++) {
        for (int j = 0; j < s->size_length; j++) {
            verif_comparaison(back_world, world, i, j);
        }
    }
}
