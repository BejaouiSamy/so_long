#ifndef SO_LONG_H
# define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct s_animation {
    void *img_left[3];      // Images pour animation gauche
    void *img_right[3];     // Images pour animation droite
    int current_frame;      // Frame actuelle
    int animation_active;   // Si une animation est en cours
    int direction;          // 0 pour gauche, 1 pour droite
    int frame_counter;      // Pour contrôler la vitesse d'animation
    int x;
    int y;
} t_animation;




typedef struct s_map
{
    char **grid;
    int width;
    int height;
    int collectibles;
    int exit;
    int exit_count;
    int player;
} t_map;

typedef struct s_textures
{
    void *wall;
    void *floor;
    void *collectible;
    void *player;
    void *exit_frames[6];
} t_textures;

typedef struct s_player
{
    int x;
    int y;
    int moves;
    int collected;
    int direction;
    int current_frame;
} t_player;

typedef struct s_game
{
    void *mlx;
    void *win;
    t_map *map;
    t_textures textures;
    t_player player;
    t_player exit;
    int exit_current_frame; // Indice de frame de sortie
    t_animation anim;
} t_game;

// Structure pour la file d'attente BFS
typedef struct s_queue
{
    int x, y;
    struct s_queue *next;
} t_queue;

// Chargement et affichage des textures
int load_textures(t_game *game);
void draw_map(t_game *game);
int animate_player(t_game *game);
int animate_exit(t_game *game);
int game_loop(t_game *game);

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
void collect_item(t_game *game);

// Gestion de la map
int parse_map(t_game *game, char *filename);
int add_line_to_map(t_game *game, char *line);
int validate_map(t_game *game);
void free_map(t_map *map);
void free_game(t_game *game);
void free_textures(t_game *game);
void count_map_elements(t_game *game, char *line, int y);

// Checking path
void enqueue(t_queue **queue, int x, int y);
void dequeue(t_queue **queue);
int is_valid_position(t_map *map, int x, int y, char **visited);
int check_path(t_game *game);



# endif