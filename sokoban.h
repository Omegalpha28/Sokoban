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
    char *wall;
    char *player;
    char *box;
    char *goal;
    int pos_x;
    int pos_y;
}element;
typedef struct {
    int size_col;
    int size_length;
    int playing;
    int stuck;
}size_tab;
int my_strcmp(char const *s1, char const *s2);
char my_putchar(char a);
int my_putstr(char const *str);
void my_display_in_center(WINDOW *stdscr, char **world, size_tab *s,
    element *e);
int num_len(int n);
int my_put_nbr(int nb);
void display(char **world, size_tab *s, element *e);
int my_strlen(char const *str);
int sokoban(char **av, int fd);
int is_help(char **av);
void my_help(void);
char **my_convert_tab(char const *word, char **world, int size, int longeur_j);
void append(char **world, int i, int j, char const *word);
int my_column(char const *word);
int my_length(char const *word);
int create_tab(char const *word);
void search_player(char **world, element *e);
void where_is_player(char **world, element *e, int i, int j);
int verif_word(char const *word);
int moving_player(element *e, char **world, int playing, int t_pressed);
int is_moving(element *e, char **world, int move_x, int move_y);
int is_moving_with_box_x(element *e, char **world, int move_x, int move_y);
int is_moving_with_box_y(element *e, char **world, int move_x, int move_y);
int is_moving(element *e, char **world, int move_x, int move_y);
int search_goal(char **world, size_tab *s);
int is_goal(char **world, size_tab *s, int i, int j);
void my_box(char **world, size_tab *s, int search_goal);
int comparate_my_box(int blocked, int count_box_stuck, int search_goal,
    size_tab *s);
int my_box_is_here(char **world, int i, int j);
int verify_box(char **world, int i, int j);
void test(char w, int i, int j, element *e);
#endif
