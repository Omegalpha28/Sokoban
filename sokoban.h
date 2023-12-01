/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** header for SOKOBAN
*/

#ifndef SOKOBAN_
    #define SOKOBAN_
    #include <curses.h>
typedef struct {
    char wall;
    char player;
    char box;
    char goal;
    int pos_x;
    int pos_y;

}element;
int my_strcmp(char const *s1, char const *s2);
char my_putchar(char a);
int my_putstr(char const *str);
void my_display_in_center(WINDOW *stdscr, char **word, int size_col);
int num_len(int n);
int my_put_nbr(int nb);
void display(char **world, int size_col);
int my_strlen(char const *str);
int sokoban(char **av, int fd);
int is_help(char **av);
void my_help(void);
char **my_convert_tab(char const *word, char **world, int size, int longeur_j);
void append(char **world, int i, int j, char const *word);
int my_column(char const *word);
int my_length(char const *word);
int create_tab(char const *word);
#endif
