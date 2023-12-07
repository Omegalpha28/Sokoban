/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** it'll check if my box is blocked or not
*/
#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"

int size_verif(int size, int longeur)
{
    if (size < longeur ) {
        return longeur;
    } else {
        return size;
    }
}

int verify_box(char **world, int i, int j)
{
    if (world[i][j] == 'X') {
        if ((world[i][j - 1] == '#' || world[i][j + 1] == '#') &&
            (world[i - 1][j] == '#' || world[i + 1][j] == '#'))
            return 1;
    }
    return 0;
}

int comparate_my_box(int blocked, int count_box_stuck)
{
    if (blocked == 1) {
        count_box_stuck += 1;
        return count_box_stuck;
    } else {
        return count_box_stuck;
    }
}

int my_box(char **world, size_tab *s, int search_goal)
{
    int blocked = 0;
    int count_box_stuck = 0;

    for (int i = 0; i < s->size_col; i++) {
        for (int j = 0; j < s->size_length; j++) {
            blocked = verify_box(world, i, j);
            count_box_stuck = comparate_my_box(blocked, count_box_stuck);
        }
    }
    if (count_box_stuck == search_goal)
        return 1;
    return 0;
}
