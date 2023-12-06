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
    int wall_count = 0;

    if (world[i][j] == 'X') {
        if (world[i - 1][j] == '#' && world[i][j - 1] == '#')
            wall_count++;
        if (world[i  + 1][j] == '#' && world[i - 1][j] == '#')
            wall_count++;
        if (world[i][j - 1] == '#')
            wall_count++;
        if (world[i][j + 1] == '#')
            wall_count++;
    }
    return wall_count;
}

int comparate_my_box(int blocked, int count_box_stuck, int search_goal,
    size_tab *s)
{
    if (blocked >= 2) {
        count_box_stuck += 1;
        return count_box_stuck;
    } else {
        return 0;
    }
}

int my_box(char **world, size_tab *s, int search_goal)
{
    int blocked = 0;
    int count_box_stuck = 0;

    for (int i = 0; i < s->size_col; i++) {
        for (int j = 0; j < s->size_length; j++) {
            blocked = 0;
            blocked = verify_box(world, i, j);
            count_box_stuck = comparate_my_box(blocked, count_box_stuck,
                search_goal, s);
        }
    }
    if (count_box_stuck == search_goal)
        return 1;
}
