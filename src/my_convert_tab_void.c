/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** string to tab for my backup_world
*/
#include <stdio.h>
#include <stdlib.h>
#include "../sokoban.h"

void append2(char **world, int i, int j, char const *word)
{
    if (word[i] == '#' || word[i] == 'O' || word[i] == ' ') {
        world[j][i] = word[i];
    } else if (word[i] == 'P' || word[i] == 'X') {
        world[j][i] = ' ';
    }
}

char **my_convert_tab_void(char const *word, char **world, int size,
    int longeur_j)
{
    int j = 0;

    for (int i = 0; i < size; i++) {
        world[i] = malloc(sizeof(char) * (longeur_j + 1));
        j = 0;
        for (j = 0; j < longeur_j && word[j] != '\n' && word[j] != '\0'; j++) {
            append2(world, j, i, word);
        }
        world[i][j] = '\0';
        if (word[j] == '\n') {
            j++;
            word += j;
        } else {
            break;
        }
    }
    world[size] = NULL;
    return world;
}
