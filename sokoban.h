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
    char *player;
    char box;
    char goal;
    int pos_x;
    int pos_y;
}element;
typedef struct {
    int size_col;
    int size_length;
    int playing;
    int stuck;
    int goal;
}size_tab;
void append(char **world, int i, int j, char const *word);
void append2(char **world, int i, int j, char const *word);
int comparate_my_box(int blocked, int count_box_stuck);
void compare_world(char **back_world, char **world, size_tab *s);
int create_tab(char const *word, element *e);
void display(char **world, size_tab *s, element *e, char **backup_world);
int end_game(char **world, size_tab *s);
int is_goal(char **world, element *e, int i, int j);
int is_help(char **av, element *e);
int is_moving(element *e, char **world, int move_x, int move_y);
int is_moving_with_box(element *e, char **world, int move_x, int move_y);
int is_moving_with_box_x(element *e, char **world, int move_x);
int is_moving_with_box_y(element *e, char **world, int move_y);
int moving_player(element *e, char **world, char **back_world, int t_pressed);
int my_box(char **world, size_tab *s, int search_goal);
int my_column(char const *word);
char **my_convert_tab(char const *word, char **world, int size, int longeur_j);
char **my_convert_tab_void(char const *word, char **world, int size,
    int longeur_j);
void my_display_in_center(WINDOW *stdscr, char **world, size_tab *s,
    element *e);
void my_display_world(char **world, size_tab *s, element *e);
void my_help(void);
int my_length(char const *word);
char my_putchar(char a);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int num_len(int n);
void search_box(char **world, element *e);
int search_goal(char **world, size_tab *s, element *e);
void search_player(char **world, element *e);
int size_verif(int size, int longeur);
int sokoban(char **av, int fd, element *e);
void test(char w, int i, int j, element *e);
void verif_comparaison(char **back_world, char **world, int i, int j);
void verif_display_world(char w, int i, int j, element *e);
int verif_end_game(char w);
int verif_word(char const *word);
int verify_box(char **world, int i, int j);
void where_is_box(char **world, element *e, int i, int j);
void where_is_player(char **world, element *e, int i, int j);
#endif
