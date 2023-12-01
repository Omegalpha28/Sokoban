/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** string to tab
*/
#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"

int my_length(char const *word)
{
    int longeur = 0;
    int i = 0;

    while (word[i] != '#') {
        i++;
    }
    for (i; word[i] != '\n'; i++){
        longeur++;
    }
    return longeur;
}

int my_column(char const *word)
{
    int column = 0;
    int i = 0;

    while (word[i] != '#') {
        i++;
    }
    for (i; word[i] != '\0'; i++){
        if (word[i] == '\n')
            column++;
    }
    return column + 1;
}

void append(char **world, int i, int j, char const *word)
{
    if (word[i] == '#' || word[i] == 'P' || word[i] == 'O' || word[i] == 'X' ||
        word[i] == ' ') {
        world[j][i] = word[i];
    }
}

char **my_convert_tab(char const *word, char **world, int size, int longeur_j)
{
    int j = 0;

    for (int i = 0; i < size; i++) {
        world[i] = malloc(sizeof(char) * (longeur_j + 1));
        j = 0;
        for (j = 0; j < longeur_j && word[j] != '\n' && word[j] != '\0'; j++) {
            append(world, j, i, word);
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
