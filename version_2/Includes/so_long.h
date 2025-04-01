#ifndef SO_LONG_H
# define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

extern int g_chest_counter;
extern int g_exit_counter;

typedef struct s_map
{
    char **grid;
    int width;
    int height;
    int collectibles;
    int gelano;
    int popo;
    int glove;
    int exit;
    int player;
} t_map;

typedef struct s_textures
{
    void *wall;
    void *floor;
    void *collectible;
    void *player;
    void *gelano;
    void *popo;
    void *glove;
    void *enemy;
    void *enemy_right;
    void *enemy_left;
    void *exit_frames[6];
    void *chest_frames[4];
} t_textures;

typedef struct s_enemy {
    int x;
    int y;
    int dir;
} t_enemy;

typedef struct s_player {
    int x;
    int y;
} t_player;

typedef struct s_game {
    void *mlx;
    void *win;
    t_map *map;
    t_textures textures;
    t_player player;
    t_player exit;
    int exit_current_frame; // Indice de frame de sortie
    int chest_current_frame;
    t_enemy enemy;
    int enemy_timer;
    int steps;
} t_game;

// Structure pour la file d'attente BFS
typedef struct s_queue
{
    int x;
    int y;
    struct s_queue *next;
} t_queue;

// Chargement et affichage des textures
int load_textures(t_game *game);
void draw_map(t_game *game);
int animate_exit(t_game *game, int *exit_counter);
int game_loop(t_game *game);
int load_basic_textures(t_game *game, int *width, int *height);
int load_exit_textures(t_game *game, int *width, int *height);

// Gestion de `get_next_line`
int ft_strlen_until(char *str, char c);
void ft_smemcpy(char *dest, char *src, int n);
char *ft_sstrdup(char *s);
char *ft_append_buffer(char *line, char *buffer, int line_len, int buffer_len);
int has_char(char *str, char c);
char *extract_line(char **stash);
char *get_next_line(int fd);

// Gestion des entrées et mouvements
void move_player(t_game *game, int dx, int dy);
int key_press(int keycode, t_game *game);

// Gestion de la map
int parse_map(t_game *game, char *filename);
int add_line_to_map(t_game *game, char *line);
int validate_map(t_game *game);
void free_map(t_map *map);
int free_game(t_game *game);
void free_textures(t_game *game);
void count_map_elements(t_game *game, char *line, int y);
int checks_wall(t_game *game);
int check_horizontal_walls(t_game *game);
int check_vertical_walls(t_game *game);
int read_map_file(t_game *game, int fd);
int init_map_structures(t_game *game);
int check_line_validity(t_game *game, char *line, int *len);
int allocate_new_grid(t_game *game, char *line, char ***new_grid);
int check_file_extension(char *str);

// Checking path
void enqueue(t_queue **queue, int x, int y);
void dequeue(t_queue **queue);
int is_valid_position(t_map *map, int x, int y, char **visited);
int check_path(t_game *game);

//int animate_chest(t_game *game);
int animate_chest(t_game *game, int *frame_counter);
int load_chest_textures(t_game *game, int *width, int *height);

// Gestion des ennemis
void move_enemies(t_game *game);
void check_collision(t_game *game);
void add_enemy(t_game *game, int x, int y);

void display_steps(t_game *game);

void free_loop(t_game *game);
void draw_map_1(t_game *game, int y, int x);
int check_cell(t_game *game, char new_cell);
void load_basic_texture_1(t_game *game, int *width, int *height);

void extract_line_1(char **stash, char **line, int *line_len);
int initialize_game(t_game *game, char *map_path);
int handle_error(char *msg, t_game *game);

int bfs(t_game *game, char **visited, int *c_found, int *e_found);
char **init_visited(t_game *game);
void free_visited(char **visited, int height);
void process_node(t_game *game, char **visited, int x, int y, int *c_found, int *e_found, t_queue **queue);
void print_game_info(t_game *game);
void update_x_position(t_game *game);

int init_collectible_instances(t_game *game);
void tab_texture(t_game *game, int width, int height);

void process_map_element(t_game *game, char element, int x, int y);
void count_collectibles(t_game *game, char element);
void exit_handling(t_game *game, char new_cell);
int handle_collectibles(t_game *game, char new_cell);

# endif